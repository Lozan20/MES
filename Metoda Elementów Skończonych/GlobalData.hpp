#pragma once
#include <string>
#include <vector>

#include "FileRead.hpp"

class GlobalData
{
	float W; // Width
	float H; // Height
	int nW; // number of nodes in width
	int nH; // number of nodes in height
	int nN; // number of nodes
	int nE; // number od elements
	double wage;
	double alfa;
	double N;
	double ro;
	double c;
	double t0;
	double ta;
	double conductivity;


public:
	double get_n() const
	{
		return N;
	}

	double get_alfa() const
	{
		return alfa;
	}

	void set_alfa(double alfa)
	{
		this->alfa = alfa;
	}

	void set_n(double n)
	{
		N = n;
	}

	double get_wage() const
	{
		return wage;
	}

	double get_t0() const
	{
		return t0;
	}

	void set_t0(double t0)
	{
		this->t0 = t0;
	}

	double get_ta() const
	{
		return ta;
	}

	void set_ta(double ta)
	{
		this->ta = ta;
	}

	void set_wage(double wage)
	{
		this->wage = wage;
	}


	GlobalData(const char* filepath)
	{
		std::vector<float> data = FileRead::file_read(filepath);
		W = data[0];
		H = data[1];
		nH = data[2];
		nW = data[3];
		alfa = data[4];
		wage = data[5];
		c = data[6];
		ro = data[7];
		t0 = data[8];
		ta = data[9];
		conductivity = data[10];

		if (wage == 2) N = 4;
		if (wage == 3) N = 9;
		if (wage == 4)N = 16;
		nE = (nH - 1) * (nW - 1);
		nN = nH * nW;
	}

	double get_conductivity() const
	{
		return conductivity;
	}

	void set_conductivity(double conductivity)
	{
		this->conductivity = conductivity;
	}

	double get_ro() const
	{
		return ro;
	}

	void set_ro(double ro)
	{
		this->ro = ro;
	}

	double get_c() const
	{
		return c;
	}

	void set_c(double c)
	{
		this->c = c;
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
