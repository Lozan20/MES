#pragma once

#include "MatrixGlobal.hpp"
#include "ShapeFunctions.hpp"
#include "BoundaryCondition.hpp"


#define FILEPATH "data.txt"
GlobalData gl(FILEPATH);
const int detN = gl.get_n();
const int fragmentation = gl.get_wage();
const double conductivity = gl.get_conductivity();
const double ro = gl.get_ro();
const double c = gl.get_c();
const double ta = gl.get_ta();
const double t0 = gl.get_t0();

int main()
{
	FemGrid fg(gl);
	Wages w(gl.get_wage());
	ShapeFunctions sf(w.get_coordinates());

	std::vector<Local> jakobiany;
	for (auto i : fg.get_elem())
	{
		jakobiany.push_back(Local(w, fg, i));
	}

	std::vector<MatrixH> matrixH;
	for (auto i : jakobiany)
	{
		matrixH.push_back(MatrixH(i, w));
	}
	BoundaryCondition P(fg.elem.size());
	P.add_boundary_condition(matrixH, fg, w);
	std::vector<MatrixC> matrixC;
	for (auto i : jakobiany)
	{
		matrixC.push_back(MatrixC(sf.get_shapefun(), w.get_linew(), i.getDetJ()));
	}

	MatrixGlobal m(fg, matrixH, matrixC,P);

	return 0;
}
