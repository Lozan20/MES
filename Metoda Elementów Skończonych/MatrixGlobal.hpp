#include "MatrixC.hpp"
#include "MatrixH.hpp"

class MatrixGlobal
{
	std::vector<std::vector<double>> global_h;
	std::vector<std::vector<double>> global_c;
public:
	MatrixGlobal(FemGrid fg, std::vector<MatrixH> matrixH,std::vector<MatrixC> matrixC)
	{
		int size = fg.get_node().size();
		global_h.resize(size);
		global_c.resize(size);
		for (int i = 0; i < size; i++)
		{
			global_h[i].resize(size);
			global_c[i].resize(size);
		}
		
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int i = 0; i < matrixH.size(); i++)
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
};