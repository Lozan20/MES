#ifndef WAGES_HPP
#define WAGES_HPP
#include <vector>
class Wages
{
	std::vector<Node*> coordinates;
	double** wages;
	int size;
	std::vector<double> linew;
public:
	std::vector<double> basic_w;

	Wages(int size_) : size(size_)
	{
		wages = new double* [size];
		for(int i = 0;i<size;i++)
		{
			wages[i] = new double[size];
		}
		if (size == 2)
		{
			twoPoints();
			setTwoCoordinates();
		}
		if (size == 3)
		{
			threePoints();
			setThreeCoordinates();
		}
		if(size == 4)
		{
			setFourCoordinates();
			fourPoints();
		}
	}
	
	~Wages()
	{
		
	}
private:
	void setTwoCoordinates()
	{
		double temp = 1.0 / sqrt(3);

		coordinates.push_back(new Node(-temp, -temp));
		coordinates.push_back(new Node(temp, -temp));
		coordinates.push_back(new Node(temp, temp));
		coordinates.push_back(new Node(-temp, temp));

	}
	void setThreeCoordinates() 
	{
		double temp = sqrt(3.0/5.0);

		coordinates.push_back(new Node(-temp, -temp));
		coordinates.push_back(new Node(0.0, -temp));
		coordinates.push_back(new Node(temp, -temp));
		coordinates.push_back(new Node(-temp, 0.0));
		coordinates.push_back(new Node(0.0, 0.0));
		coordinates.push_back(new Node(temp, 0.0));
		coordinates.push_back(new Node(-temp, temp));
		coordinates.push_back(new Node(0.0, temp));
		coordinates.push_back(new Node(temp, temp));

	}
	void setFourCoordinates()
	{
		double temp1 = 0.861136;
		double temp2 = 0.339981;
		coordinates.push_back(new Node(-temp1, -temp1));
		coordinates.push_back(new Node(-temp2, -temp1));
		coordinates.push_back(new Node(temp2, -temp1));
		coordinates.push_back(new Node(temp1, -temp1));
		coordinates.push_back(new Node(-temp1, -temp2));
		coordinates.push_back(new Node(-temp2, -temp2));
		coordinates.push_back(new Node(temp2, -temp2));
		coordinates.push_back(new Node(temp1, -temp2));
		coordinates.push_back(new Node(-temp1, temp2));
		coordinates.push_back(new Node(-temp2, temp2));
		coordinates.push_back(new Node(temp2, temp2));
		coordinates.push_back(new Node(temp1, temp2));
		coordinates.push_back(new Node(-temp1, temp1));
		coordinates.push_back(new Node(-temp2, temp1));
		coordinates.push_back(new Node(temp2, temp1));
		coordinates.push_back(new Node(temp1, temp1));
	}
	
	void twoPoints()
	{
		basic_w.push_back(1.0);
		basic_w.push_back(1.0);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				wages[i][j] = 1;
				linew.push_back(1);
			}

		}
	}

public:
	std::vector<double> get_linew() const
	{
		return linew;
	}

	void set_linew(const std::vector<double>& linew)
	{
		this->linew = linew;
	}

private:
	void threePoints()
	{
		double tab[3] = { 5.0/9.0,8.0/9.0,5.0/9.0 };
		basic_w.push_back(5.0 / 9.0);
		basic_w.push_back(8.0 / 9.0);
		basic_w.push_back(5.0 / 9.0);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				wages[i][j] = tab[i] * tab[j];
				linew.push_back(wages[i][j]);
			}
		}
	}
	void fourPoints()
	{
		double tab[4] = { 0.347855,0.652145,0.652145,0.347855};
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				wages[i][j] = tab[i] * tab[j];
				linew.push_back(wages[i][j]);
			}
		}
	}
public:

	int get_size() const
	{
		return size;
	}

	void set_size(int size)
	{
		this->size = size;
	}

	double** get_wages() const
	{
		return wages;
	}

	void set_wages(double** wages)
	{
		this->wages = wages;
	}

	std::vector<Node*> get_coordinates() const
	{
		return coordinates;
	}

	void set_coordinates(std::vector<Node*> coordinates)
	{
		this->coordinates = coordinates;
	}

};
#endif // WAGES_HPP
