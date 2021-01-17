#pragma once
#include "MatrixGlobal.hpp"
#include "ShapeFunctions.hpp"
#include "BoundaryCondition.hpp"
#include "Solve_FEM.hpp"
#include "Bucket_Grid.hpp"
#include "TimeMeasurement.hpp"

#define FILEPATH "data.txt"

GlobalData gl(FILEPATH);
const int detN = gl.get_n();
const int fragmentation = gl.get_wage();
const double alfa = gl.get_alfa();
const double ro = gl.get_ro();
const double c = gl.get_c();
const double ta = gl.get_ta();
const double t0 = gl.get_t0();
const double conductivity = gl.get_conductivity();
const int timestep = gl.get_timestep();
const int totaltime = gl.get_totaltime();


int main()
{
	TimeMeasurement time;
	time.start();
	FemGrid *fg= new FemGrid(gl);
	std::cout << "Fem Grid generated..\n";
	Wages *w= new Wages(gl.get_wage());
	std::cout << "Wages loaded...\n";
	ShapeFunctions sf(w->get_coordinates(),detN);
	std::cout << "Shape Functions calculated...\n";
	std::vector<Local*> *jakobiany = new std::vector<Local*>;
	for (auto i : fg->get_elem())
	{
			jakobiany->emplace_back(new Local(*w, *fg, i));
	}
	std::cout << "Global to local transformation done...\n";
	std::vector<MatrixH*> *matrixH = new std::vector<MatrixH*>;

	for (auto i : *jakobiany)
	{
		matrixH->push_back(new MatrixH(*i, *w));
	}
	std::cout << "H matrixes generated...\n";
	BoundaryCondition p(fg->elem.size());
	p.add_boundary_condition(*matrixH, *fg, *w);
	std::cout << "Boundary Condition and P vector generated...\n";
	std::vector<MatrixC*> *matrixC = new std::vector<MatrixC*>;
	for (auto i : *jakobiany)
	{
		matrixC->push_back(new MatrixC(sf.get_shapefun(), w->get_linew(), i->getDetJ()));
	}
	for (Local* element : *jakobiany)
	{
		delete element;
	}
	delete w;
	std::cout << "C matrixes generated...\n";
	MatrixGlobal m(*fg, *matrixH, *matrixC, p);
	std::cout << "Global matrixes generated...\n";
	for (MatrixH* element : *matrixH)
	{
		delete element;
	}

	for (auto element : *matrixC)
	{
		delete element;
	}
	delete matrixC;
	delete matrixH;
	delete fg;
	
	Solve_FEM::solve(m);
	time.stop();
	getchar();
	return 0;
}
