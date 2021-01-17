#ifndef SHAPEFUNCTIONS
#define SHAPEFUNCTIONS
#include <vector>
#include "Node.hpp"

class ShapeFunctions
{
	std::vector<std::vector<double>> shapefun;
public:
	ShapeFunctions(std::vector<Node*> w,int size)
	{
		shapefun.resize(size);
		for (int i = 0; i < size; i++)
		{
			shapefun[i].push_back(0.25 * (1 - w[i]->get_x()) * (1 - w[i]->get_y()));
			shapefun[i].push_back(0.25 * (1 + w[i]->get_x()) * (1 - w[i]->get_y()));
			shapefun[i].push_back(0.25 * (1 + w[i]->get_x()) * (1 + w[i]->get_y()));
			shapefun[i].push_back(0.25 * (1 - w[i]->get_x()) * (1 + w[i]->get_y()));
		}
	}
	std::vector<std::vector<double>> get_shapefun()
	{
		return shapefun;
	}

	void set_shapefun(const std::vector<std::vector<double>>& shapefun)
	{
		this->shapefun = shapefun;
	}
};
#endif