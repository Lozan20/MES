#ifndef SOLVE_FEM
#define SOLVE_FEM
#include "MatrixGlobal.hpp"
#include <algorithm>
class Solve_FEM
{
	public:
	static std::vector<double> &solve(const MatrixGlobal &matrix_global)
	{
		std::vector<double> t1;
		std::vector<double> t2;
		t2.resize(matrix_global.get_global_c().size());
		for (int i = 0; i < matrix_global.get_global_h().size(); i++) t1.push_back(t0);
		int nt = 100;
		auto  m=H(matrix_global.get_global_h(), matrix_global.get_global_c());
		auto p=P(matrix_global.get_global_c(), matrix_global.get_global_p(),t1);
		for (int i = 0; i < m.size(); i++)
		{
			m[i].push_back(p[i]);
		}
		for(int n=0;n<nt;n++)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int k = 0; k < t2.size(); k++) {
					t2[k] = m[k][m.size()];
					for (int j = 0; j < m.size(); j++) {
						if (j != k) t2[k] = t2[k] - (m[k][j] * t1[j]);
					}
					t2[k] /= m[k][k];
				}
				t1 = t2;
				t2.clear();
				t2.resize(matrix_global.get_global_c().size());
			}
			p = P(matrix_global.get_global_c(), matrix_global.get_global_p(), t1);
			for (int i = 0; i < m.size(); i++)
			{
				m[i].back() = p[i];
			}
			std::cout << "Time: " << n << "s" << "Max temp: " <<  *std::max_element(t1.begin(),t1.end()) << " Min temp: " << *std::min_element(t1.begin(), t1.end()) << std::endl;
		}
		return t1;

	}
	static std::vector<std::vector<double>> H(const std::vector<std::vector<double>> &H_, const std::vector<std::vector<double>>&C_)
	{
		std::vector<std::vector<double>> h;
		h.resize(H_.size());
		for (int i = 0; i<H_.size();i++)
		{
			for (int j = 0; j<H_.size(); j++)
			{
				h[i].push_back(H_[i][j] + (C_[i][j] / 1.0));
			}
		}
		return h;
	}
	static std::vector<double> P(const std::vector<std::vector<double>> &C_, const std::vector<double>&P_, std::vector<double> &t0)
	{
		double temp = 0.0;
		std::vector<double> p;
		for(int i = 0 ;i< C_.size();i++)
		{
			temp = 0.0;
			for (int j = 0; j < C_.size(); j++)
			{
				temp +=  ((C_[i][j]/1.0) * t0[j]);
			}
			p.push_back(temp + P_[i]);
		}
		return p;
	}

};
#endif