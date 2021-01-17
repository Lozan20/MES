#ifndef MATRIXGLOBAL
#define MATRIXGLOBAL
#include "BoundaryCondition.hpp"
#include "MatrixC.hpp"
#include "MatrixH.hpp"
#include <omp.h>
#include <concurrent_vector.h>
class MatrixGlobal
{
	std::vector<std::vector<double>> global_h;
	std::vector<std::vector<double>> global_c;
	std::vector<double> global_p;
public:
	MatrixGlobal(FemGrid &fg, std::vector<MatrixH*> &matrixH,std::vector<MatrixC*> &matrixC,BoundaryCondition &bc)
	{
		int size = fg.get_node().size();
		setSize(size);
		int i, j, k;
			#pragma omp parallel for private(i,j,k)
			for (i = 0; i < fg.elem.size(); i++)
			{
				for (j = 0; j < 4; j++)
				{
					global_p[fg.get_elem()[i].getID()[j] - 1] += bc.get_p()[i][j];
					for (k = 0; k < 4; k++)
					{
						global_h[fg.get_elem()[i].getID()[j] - 1][fg.get_elem()[i].getID()[k] - 1] += matrixH[i]->H[j][k];
						global_c[fg.get_elem()[i].getID()[j] - 1][fg.get_elem()[i].getID()[k] - 1] += matrixC[i]->C[j][k];
					}
				}
			}
	}
	void setSize(int size)
	{
		global_h.resize(size);
		global_c.resize(size);
		global_p.resize(size);
		for (int i = 0; i < size; i++)
		{
			global_h[i].resize(size);
			global_c[i].resize(size);
		}
	}
	std::vector<std::vector<double>> get_global_h() const
	{
		return global_h;
	}

	void set_global_h(const std::vector<std::vector<double>>& global_h)
	{
		this->global_h = global_h;
	}

	std::vector<std::vector<double>> get_global_c() const
	{
		return global_c;
	}

	void set_global_c(const std::vector<std::vector<double>>& global_c)
	{
		this->global_c = global_c;
	}

	std::vector<double> get_global_p() const
	{
		return global_p;
	}

	void set_global_p(const std::vector<double>& global_p)
	{
		this->global_p = global_p;
	}
};
#endif

