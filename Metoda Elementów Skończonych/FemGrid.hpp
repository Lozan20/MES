#pragma once

#include <vector>


#include "Element.hpp"
#include "Node.hpp"

class FemGrid
{
	std::vector<Element> elem;
	std::vector<Node> node;
public:
	FemGrid(const GlobalData& data)
	{
		float dx = (data.get_w() / (data.get_n_w() - 1));
		float dy = (data.get_h() / (data.get_n_h() - 1));
		
		for (int i = 0; i < data.get_n_w(); i++)
		{
			for (int j = 0; j < data.get_n_h(); j++)
			{
				node.push_back(Node(i, j, dx, dy));
			}
		}
		int id = 1;
		for (int i = 0; i < (data.get_n_h() - 1) * (data.get_n_w() - 1); i++)
		{
			elem.push_back(Element(static_cast<int>(data.get_n_h()), id));
			id++;
			if(id%static_cast<int>(data.get_n_h())==0)
			{
				id++;
			}
		}
	}
};
