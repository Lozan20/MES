#ifndef BDSHAPEFUNCTIONS
#define BDSHAPEFUNCTIONS
#include <vector>
#include "ShapeFunctions.hpp"
#include "Node.hpp"

class BDShapeFunctions
{
	std::vector<std::vector<double>> shapefunctions;
public:
	BDShapeFunctions()
	{
		if (fragmentation == 2 )
		{
			twoPoints();

		}
		if (fragmentation == 3)
		{
			threePoints();

		}
		if (fragmentation == 4)
		{
			fourPoints();
		}
	}
	std::vector<std::vector<double>> get_shapefun()
	{
		return shapefunctions;
	}

	void set_shapefun(const std::vector<std::vector<double>>& shapefun)
	{
		this->shapefunctions = shapefun;
	}
	void twoPoints()
	{

		std::vector<Node*> cords;
		double temp = 1.0 / sqrt(3);
		cords.push_back(new Node(-temp, -1));
		cords.push_back(new Node(temp, -1));
		
		cords.push_back(new Node(1, -temp));
		cords.push_back(new Node(1, temp));
		
		cords.push_back(new Node(temp, 1));
		cords.push_back(new Node(-temp, 1));
		
		cords.push_back(new Node(-1, temp));
		cords.push_back(new Node(-1, -temp));
		shapefunctions = ShapeFunctions(cords, 8).get_shapefun();

	}
	void threePoints()
	{
		std::vector<Node*> cords;
		double temp = sqrt(3.0 / 5.0);
		
		cords.push_back(new Node(-temp, -1));
		cords.push_back(new Node(0, -1));
		cords.push_back(new Node(temp, -1));
		
		cords.push_back(new Node(1, -temp));
		cords.push_back(new Node(1, 0));
		cords.push_back(new Node(1, temp));
		
		cords.push_back(new Node(temp, 1));
		cords.push_back(new Node(0, 1));
		cords.push_back(new Node(-temp, 1));
		
		cords.push_back(new Node(-1, temp));
		cords.push_back(new Node(-1, 0));
		cords.push_back(new Node(-1, -temp));
		shapefunctions = ShapeFunctions(cords,12).get_shapefun();
		
	}
	void fourPoints()
	{
		double temp = 0.0;
		std::vector<Node*> cords;
		temp = 1.0 / sqrt(3);
		cords.push_back(new Node(-temp, -1));
		cords.push_back(new Node(temp, -1));
		cords.push_back(new Node(1, -temp));
		cords.push_back(new Node(1, temp));
		cords.push_back(new Node(temp, 1));
		cords.push_back(new Node(-temp, 1));
		cords.push_back(new Node(-1, temp));
		cords.push_back(new Node(-1, -temp));
	}

};
#endif