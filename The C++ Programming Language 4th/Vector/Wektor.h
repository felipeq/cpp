class Wektor
{
public:
	Wektor(int s);
	int size();
	double& operator[](int i);
	void show(int i);
private:
	double* elements;
	int s;
};