#ifndef NODE
#define NODE
class Node
{
	double x, y;
	bool BC;
public:
	bool is_bc() const
	{
		return BC;
	}

	void set_bc(bool bc)
	{
		BC = bc;
	}

	Node() : x(0), y(0)
	{
	}
	Node(int i,int j,double dx,double dy)
	{
		this->x = i * dx;
		this->y = j * dy;
	}
	Node(int i, int j, double dx, double dy,bool bc)
	{
		this->x = i * dx;
		this->y = j * dy;
		BC = bc;
	}
	Node(double x_,double y_) : x(x_),y(y_){}
	~Node() = default;

	double get_x() const { return x; }
	void set_x(double x) { this->x = x; }
	double get_y() const{ return y; }
	void set_y(double y){ this->y = y; }
	void set_x_y(double x,double y){this->x = x; this->y = y;}
};
#endif
