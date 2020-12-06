#include <vector>

#include "GL.h"


class MatrixC
{
public:
	std::vector<std::vector<std::vector<double>>> C_local;
	std::vector<std::vector<double>> C;
public:
	MatrixC(std::vector<std::vector<double>> shapefun, std::vector<double> linew,std::vector<double> detJ)
	{
		C_local.resize(detN);
		for (int i = 0; i < detN; i++)
		{
			C_local[i].resize(4);
			for (int j = 0; j < 4; j++)
			{
				C_local[i][j].resize(4);
			}
		}
		double temp = 0.0;
		C.resize(4);
		for (int m = 0; m < detN; m++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					temp = linew[m] * (shapefun[m][i] * shapefun[m][j] ) *7800*700* detJ[m];
					C_local[m][i][j] = temp;
				}
			}

		}
		temp = 0.0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int m = 0; m < detN; m++)
				{
					temp += C_local[m][i][j];
				}

				C[i].push_back(temp);
				temp = 0.0;
			}
		}
		
	}
};
