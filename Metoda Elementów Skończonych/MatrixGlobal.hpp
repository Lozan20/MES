#include "BoundaryCondition.hpp"
#include "MatrixC.hpp"
#include "MatrixH.hpp"

class MatrixGlobal
{
	std::vector<std::vector<double>> global_h;
	std::vector<std::vector<double>> global_c;
	std::vector<double> global_p;
public:
	MatrixGlobal(FemGrid fg, std::vector<MatrixH> matrixH,std::vector<MatrixC> matrixC,BoundaryCondition bc)
	{
		int size = fg.get_node().size();
		setSize(size);
		for (int i = 0; i < fg.elem.size(); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				global_p[fg.get_elem()[i].getID()[j] - 1] += bc.get_p()[i][j];
				for (int k = 0; k < 4; k++)
				{
					global_h[fg.get_elem()[i].getID()[j] - 1][fg.get_elem()[i].getID()[k] - 1] += matrixH[i].H[j][k];
					global_c[fg.get_elem()[i].getID()[j] - 1][fg.get_elem()[i].getID()[k] - 1] += matrixC[i].C[j][k];
				}
			}
		}
		print(size);
	}
	void print(int size)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				std::cout << global_h[j][k];
			}
			std::cout << "\n";
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
};