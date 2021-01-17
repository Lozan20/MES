#ifndef LOCAL_HPP
#define LOCAL_HPP
#include "FemGrid.hpp"
#include "Wages.hpp"
#include "GL.h"

class Local
{
	Wages w;
	FemGrid fg;
	std::vector<Node> *detx_y;
	std::vector<double> *jakobian;
	std::vector<double> *jakobian_1;
	std::vector<double> detJ;
	std::vector<double> *N;
public:
	std::vector<Node>* getDetx_y()
	{
		return detx_y;
	}
	std::vector<double>* getjakobian()
	{
		return jakobian;
	}
	std::vector<double>* getjakobian_1()
	{
		return jakobian_1;
	}
	std::vector<double> getDetJ()
	{
		return detJ;
	}

	Local(const Wages& w_, const FemGrid& fg_,Element& elem) : w(w_), fg(fg_)
	{
		detx_y = new std::vector<Node>[detN];
		jakobian = new std::vector<double>[detN];
		jakobian_1 = new std::vector<double>[detN];
		N = new std::vector<double>[detN];
		
		fillShapeFun();
		calculate_jacobian(elem);
	}
	~Local()
	{
		delete[] detx_y;
		delete[] jakobian;
		delete[] jakobian_1;
		delete[] N;
	}
	
	void fillShapeFun()
	{
		double temp = 0.25;
		std::vector<Node*> coordinates;
		Node* tempnode = new Node();
			coordinates.push_back(new Node(-temp, -temp));
			coordinates.push_back(new Node(temp, -temp));
			coordinates.push_back(new Node(temp, temp));
			coordinates.push_back(new Node(-temp, temp));
			for (int i = 0; i < detN; i++)
			{
				tempnode->set_x_y(coordinates[0]->get_x() * (1 - w.get_coordinates()[i]->get_y()),
					coordinates[0]->get_y() * (1 - w.get_coordinates()[i]->get_x()));
				detx_y[i].push_back(*tempnode);
				
				tempnode->set_x_y(coordinates[1]->get_x() * (1 - w.get_coordinates()[i]->get_y()),
					coordinates[1]->get_y() * (1 + w.get_coordinates()[i]->get_x()));
				detx_y[i].push_back(*tempnode);

				tempnode->set_x_y(coordinates[2]->get_x() * (1 + w.get_coordinates()[i]->get_y()),
					coordinates[2]->get_y() * (1 + w.get_coordinates()[i]->get_x()));
				detx_y[i].push_back(*tempnode);

				tempnode->set_x_y(coordinates[3]->get_x() * (1 + w.get_coordinates()[i]->get_y()),
					coordinates[3]->get_y() * (1 - w.get_coordinates()[i]->get_x()));
				detx_y[i].push_back(*tempnode);
			}
		for (auto element : coordinates)
		{
			delete element;
		}
		delete tempnode;
	}
	void calculate_jacobian( Element& elem)
	{
		double x = 0.0;
		for (int i = 0 ; i < detN; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				x += detx_y[i][j].get_x() * fg.get_node()[elem.getID()[j] - 1].get_x(); 
			}
			jakobian[i].push_back(x);
			x = 0.0;
			for (int j = 0; j < 4; j++)
			{
				x += detx_y[i][j].get_x() * fg.get_node()[elem.getID()[j] - 1].get_y();
			}
			jakobian[i].push_back(x);
			x = 0.0;
			for (int j = 0; j < 4; j++)
			{
				x += detx_y[i][j].get_y() * fg.get_node()[elem.getID()[j] - 1].get_x();
			}
			jakobian[i].push_back(x );
			x = 0.0;
			for (int j = 0; j < 4; j++)
			{
				x += detx_y[i][j].get_y() * fg.get_node()[elem.getID()[j] - 1].get_y();
			}
			jakobian[i].push_back(x);
			x = 0.0;
		}
		
		for (int i = 0; i < detN; i++)
		{
			detJ.push_back(jakobian[i][0] * jakobian[i][3] - jakobian[i][2] * jakobian[i][1]);
		}
		for (int i = 0; i < detN; i++)
		{
			jakobian_1[i].push_back(1/detJ[i] * jakobian[i][3]);
			jakobian_1[i].push_back(-1/detJ[i] * jakobian[i][1]);
			jakobian_1[i].push_back(-1/detJ[i] * jakobian[i][2]);
			jakobian_1[i].push_back(1/detJ[i] * jakobian[i][0]);
		}
	}
};

#endif // LOCAL_HPP
