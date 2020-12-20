#ifndef MATRIXH
#define MATRIXH

#include "BDShapeFunctions.hpp"
#include "MatrixH.hpp"

class BoundaryCondition
{
	std::vector<std::vector<double>> P;
public:
	BoundaryCondition(int size)
	{
		P.resize(size);
		for(int i=0;i<size;i++)
		{
			P[i].resize(4);
		}
	}
	// Przechodzimy po kazdym elemencie w siatce ktore sa numerowane w ten sam sposob co macierze H i dodajemy warunki w kazdym punkcie ca³kowania ???
	// dodanie warunku brzegowego HBC = det po S ( {N}{N}^T) * dS 
	void add_boundary_condition(std::vector<MatrixH>& matrix_h, FemGrid& fg, Wages& w)
	{
		BDShapeFunctions* sf = new BDShapeFunctions();
		double L = 0.0;
		for (int i = 0; i < fg.elem.size(); i++) // po kazdym elemencie
		{
			for (int j = 0; j < fragmentation; j++) // po kazdym punkcie ca³kowania
			{
				if (fg.node[fg.elem[i].getID()[0] - 1].is_bc() && fg.node[fg.elem[i].getID()[1] - 1].is_bc())
				{
					L = sqrt(
						pow(fg.node[fg.elem[i].getID()[1] - 1].get_x() - fg.node[fg.elem[i].getID()[0] - 1].get_x(), 2)
						+ pow(fg.node[fg.elem[i].getID()[1] - 1].get_y() - fg.node[fg.elem[i].getID()[0] - 1].get_y(),
						      2)); // d³ugoœæ boku z tw pitagorasa
					for (int m = 0; m < 2; m++)
					{
						P[i][m] += alfa * ta * w.basic_w[j] * L / 2 * sf->get_shapefun()[j][m];
						for (int n = 0; n < 2; n++)
						{
							matrix_h[i].H[m][n] += w.basic_w[j] * alfa * sf->get_shapefun()[j][m] * sf->
								get_shapefun()[j][n] * L / 2; // waga * przewodzenie * wektor N * wektor N ale odwrocony * L/2;
						}
					}
				}
				if (fg.node[fg.elem[i].getID()[1] - 1].is_bc() && fg.node[fg.elem[i].getID()[2] - 1].is_bc())
				{
					L = sqrt(
						pow(fg.node[fg.elem[i].getID()[2] - 1].get_x() - fg.node[fg.elem[i].getID()[1] - 1].get_x(), 2)
						+ pow(fg.node[fg.elem[i].getID()[2] - 1].get_y() - fg.node[fg.elem[i].getID()[1] - 1].get_y(),
						      2));
					for (int m = 1; m < 3; m++)
					{
						P[i][m] += alfa * ta * w.basic_w[j] * L / 2 * sf->get_shapefun()[j + 1 *
							fragmentation][m];
						for (int n = 1; n < 3; n++)
						{
							matrix_h[i].H[m][n] += w.basic_w[j] * alfa * sf->get_shapefun()[j + 1 *
								fragmentation][m] * sf->get_shapefun()[j + 1 * fragmentation][n] * L / 2;
						}
					}
				}
				if (fg.node[fg.elem[i].getID()[2] - 1].is_bc() && fg.node[fg.elem[i].getID()[3] - 1].is_bc())
				{
					L = sqrt(
						pow(fg.node[fg.elem[i].getID()[3] - 1].get_x() - fg.node[fg.elem[i].getID()[2] - 1].get_x(), 2)
						+ pow(fg.node[fg.elem[i].getID()[3] - 1].get_y() - fg.node[fg.elem[i].getID()[2] - 1].get_y(),
						      2));
					for (int m = 2; m < 4; m++)
					{
						P[i][m] += alfa * ta * w.basic_w[j] * L / 2 * sf->get_shapefun()[j + 2 *
							fragmentation][m];
						for (int n = 2; n < 4; n++)
						{
							matrix_h[i].H[m][n] += w.basic_w[j] * alfa * sf->get_shapefun()[j + 2 *
								fragmentation][m] * sf->get_shapefun()[j + 2 * fragmentation][n] * L / 2;
						}
					}
				}
				if (fg.node[fg.elem[i].getID()[3] - 1].is_bc() && fg.node[fg.elem[i].getID()[0] - 1].is_bc())
				{
					L = sqrt(
						pow(fg.node[fg.elem[i].getID()[0] - 1].get_x() - fg.node[fg.elem[i].getID()[3] - 1].get_x(), 2)
						+ pow(fg.node[fg.elem[i].getID()[0] - 1].get_y() - fg.node[fg.elem[i].getID()[3] - 1].get_y(),
						      2));
					for (int m = 0; m < 4; m += 3)
					{
						P[i][m] += alfa * ta * w.basic_w[j] * L / 2 * sf->get_shapefun()[j + 3 *
							fragmentation][m];
						for (int n = 0; n < 4; n += 3)
						{
							matrix_h[i].H[m][n] += w.basic_w[j] * alfa * sf->get_shapefun()[j + 3 *
								fragmentation][m] * sf->get_shapefun()[j + 3 * fragmentation][n] * L / 2;
						}
					}
				}
			}
		}
		delete sf;
	}

	std::vector<std::vector<double>> get_p() const
	{
		return P;
	}

	void set_p(const std::vector<std::vector<double>>& p)
	{
		P = p;
	}
};
#endif
