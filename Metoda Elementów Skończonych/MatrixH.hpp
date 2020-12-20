#pragma once
#include <vector>
#include "Local.hpp"

class MatrixH
{
public:
	std::vector<double>* detN_x;
	std::vector<double>* detN_y;
	std::vector<std::vector<std::vector<double>>> H1_4;
	std::vector<std::vector<double>> H;
	MatrixH(Local &local, Wages& w)
	{
		detN_x = new std::vector<double>[detN];
		detN_y = new std::vector<double>[detN];
		H1_4.resize(detN);
		for (int i = 0; i < detN; i++)
		{
			H1_4[i].resize(4);
			for (int j = 0; j < 4; j++)
			{
				H1_4[i][j].resize(4);
			}
		}
		H.resize(4);

		double temp = 0.0;
		for (int i = 0; i < detN; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				temp = 1 / local.getDetJ()[i] * (local.getDetx_y()[i][j].get_x() * local.getjakobian()[i][3] + local.
					getDetx_y()[i][j].get_y() * (-local.getjakobian()[i][1]));
				detN_x[i].push_back(temp);
			}
		}
		for (int i = 0; i < detN; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				temp = 1 / local.getDetJ()[i] * (local.getDetx_y()[i][j].get_x() * (-local.getjakobian()[i][2]) + local.
					getDetx_y()[i][j].get_y() * (local.getjakobian()[i][0]));
				detN_y[i].push_back(temp);
			}
		}
		temp = 0.0;
		for (int m = 0; m < detN; m++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					temp = w.get_linew()[m] * (detN_x[m][i] * detN_x[m][j] + detN_y[m][i] * detN_y[m][j]) * conductivity
						* local.getDetJ()[m];
					H1_4[m][i][j] = temp;
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
					temp += H1_4[m][i][j];
				}

				H[i].push_back(temp);
				temp = 0.0;
			}
		}
	}
	~MatrixH()
	{
		
	}
};
