class Node
{
	float x, y;
public:
	Node() : x(0), y(0)
	{
	}
	Node(int i,int j,float dx,float dy)
	{
		this->x = i * dx;
		this->y = j * dy;
	}
	~Node() = default;

	float get_x() const { return x; }
	void set_x(float x) { this->x = x; }
	float get_y() const{ return y; }
	void set_y(float y){ this->y = y; }
};
