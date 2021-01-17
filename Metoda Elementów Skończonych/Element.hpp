#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <vector>
class Element
{
	std::vector<int> id;
public:

	Element(int nh,int i)
	{
		id.push_back(i);
		id.push_back(i + nh);
		id.push_back(i + nh + 1);
		id.push_back(i + 1);
	}
	std::vector<int> getID()
	{
		return this->id;
	}
	
};
#endif // ELEMENT_HPP
