class Matrix
{
	int n, m;
	double** var;
public:
	Matrix(int sizeN,int sizeM) : n(sizeN),m(sizeM)
	{
		var = new double* [n];
		for (int i = 0; i < n; i++)
		{
			var[i] = new double[m];
		}
	}
};