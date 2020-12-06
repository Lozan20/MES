#pragma once

#include <vector>


#include "Element.hpp"
#include "Node.hpp"

class FemGrid
{
public:
	std::vector<Element> elem;
	std::vector<Node> node;
public:
	FemGrid()
	{

	}
	FemGrid(const GlobalData& data)
	{
		float dx = (data.get_w() / (data.get_n_w() - 1));
		float dy = (data.get_h() / (data.get_n_h() - 1));
		
		for (int i = 0; i < data.get_n_w(); i++)
		{
			for (int j = 0; j < data.get_n_h(); j++)
			{

				if(i == 0 || i == data.get_n_w()-1 || j == 0 || j == data.get_n_h()-1)
				{
					node.push_back(Node(i, j, dx, dy,true));
				}
				else
				{
					node.push_back(Node(i, j, dx, dy, false));
				}

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


	std::vector<Element> get_elem() { return this->elem;}
	void set_elem(const std::vector<Element>& elem) { this->elem = elem; }
	std::vector<Node> get_node() {return this->node;}
	void set_node(const std::vector<Node>& node){this->node = node;}

};
