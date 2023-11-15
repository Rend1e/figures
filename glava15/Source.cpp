#include <iostream>
#include <cmath>

using namespace std;

class figure {
public:
	virtual void show() = 0;	
	virtual double dis() = 0;
};
class point : figure {
protected:
	int x, y;
public:
	point() : x(0), y(0)
	{}
	point(int x, int y) : x(x), y(y)
	{}
	void show()
	{
		cout << "point : ( " << x << ", " << y << " )" << endl;
	}
	double dis()
	{
		return sqrt(double(pow(x, 2) + pow(y, 2)));
	}
	int getx() { return x; }
	int gety() { return y; }
};
class pointSpace : public point
{
protected:
	int z;
public:
	pointSpace() : point(), z(0)
	{}
	pointSpace(int x, int y, int z) : point(x, y), z(z)
	{}
	void show()
	{
		cout << "point : ( " << x << ", " << y << ", " << z << " )" << endl;
	}
	double dis()
	{
		return sqrt(double(x * x + y * y + z * z));
	}
	int getz() { return z; }
};

class rectangle : public figure {
protected:
	point* q;
	int a, b;
public:
	rectangle() : a(0), b(0)
	{
		q = new point();
	}
	rectangle(int x, int y, int a, int b) : a(a), b(b)
	{
		q = new point(x, y);
	}
	void show()
	{
		cout << "rectangle : center ( " << q->getx() << ", " << q->gety() << " )" << endl;
	}
	double dis()
	{
		return sqrt(double(q->getx() * q->getx() + q->gety() * q->gety()));
	}
	double pr()
	{
		return (a + b) * 2;
	}
	double pl()
	{
		return a * b;
	}
	~rectangle()
	{
		delete q;
	}
};
class circle : public figure {
protected:
	point* a;
	int r;
public:
	circle() : r(0)
	{
		a = new point();
	}
	circle(int x, int y, int r) : r(r)
	{
		a = new point(x, y);
	}
	void show()
	{
		cout << "circle :  center ( " << a->getx() << ", " << a->gety() << " ), radius " << r << endl;
	}
	double dis()
	{
		return sqrt(double(a->getx() * a->getx() + a->gety() * a->gety()));
	}
	double pr()
	{
		return 2 * 3.14 * r;
	}
	double pl()
	{
		return 3.14 * pow(r, 2);
	}
	~circle()
	{
		delete a;
	}
	
};
class triangle : public figure {
protected:
	pointSpace* q;
	int a, b, c;
public:
	triangle() : a(0), b(0), c(0)
	{
		q = new pointSpace();
	}
	triangle(int x,int y, int z, int a, int b, int c) : a(a), b(b), c(c)
	{
		q = new pointSpace(x, y, z);
	}
	void show()
	{
		cout << "triangle center : ( " << q->getx() << ", " << q->gety() << ", " << q->getz() << " )" << endl;
	}
	double dis()
	{
		return sqrt(double(q->getx() * q->getx() + q->gety() * q->gety() + q->getz() * q->getz()));
	}
	double pr()
	{
		return a + b + c;
	}
	double pl() 
	{
		double p = pl() / 2;
		return sqrt(p * (p - 1) * (p - b) * (p - c));
	}
	~triangle()
	{
		delete q;
	}
};
int main() {

	figure* figures[6];
	figures[0] = new triangle(1, 2, 4, 3, 4, 5);
	figures[1] = new rectangle(2, 2, 3, 4);
	figures[2] = new circle(0, 1, 4);
	figures[3] = new rectangle(1, 1, 2, 2);
	figures[4] = new triangle(1, 2, 3, 3, 2, 1);
	figures[5] = new circle(2, 4, 2);

	for (int i = 0; i < 6; i++) {
		figures[i]->show();
		cout << "distance: " << figures[i]->dis() << endl;
	}

	for (int i = 0; i < 6; i++) {
		delete figures[i];
	}
	return 0;
}