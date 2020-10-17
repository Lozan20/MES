#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "FileRead.hpp"

class GlobalData
{
	float W; // Width
	float H; // Height
	float nW;// number of nodes in width
	float nH;// number of nodes in height
	float nN;// number of nodes
	float nE;// number od elements
	

public:

	GlobalData(const char* filepath)
	{
		std::vector <float> data = FileRead::file_read(filepath);
		W = data[0];
		H = data[1];
		nH = data[2];
		nW = data[3];
		nE = (nH - 1) * (nW - 1);
		nN = nH * nW;
		
		
	}
	~GlobalData() = default;

	float get_w() const
	{
		return W;
	}
	void set_w(float w)
	{
		W = w;
	}
	float get_h() const
	{
		return H;
	}
	void set_h(float h)
	{
		H = h;
	}
	float get_n_w() const
	{
		return nW;
	}
	void set_n_w(float n_w)
	{
		nW = n_w;
	}
	float get_n_n() const
	{
		return nN;
	}
	void set_n_n(float n_n)
	{
		nN = n_n;
	}
	float get_n_e() const
	{
		return nE;
	}
	void set_n_e(float n_e)
	{
		nE = n_e;
	}
	float get_n_h() const
	{
		return nH;
	}
	void set_n_h(float n_h)
	{
		nH = n_h;
	}
	
};
