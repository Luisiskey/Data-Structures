#include <iostream>
#include <cstdlib>
#include "point.hpp"
using namespace std;

using namespace ni_point;
int main(){
	point a(1,2);
	point b(1);
	point c;

	cout<<"Point a is (" << a.get_x()<<","<< a.get_y()<<")"<< endl;
	cout<<"Point b is (" << b.get_x()<<","<< b.get_y()<<")"<< endl;
	cout<<"Point c is (" << c.get_x()<<","<< c.get_y()<<")"<< endl;

	point c1, c2;
	c1 = a + b;
	c2 = a + b;
	if (c1 != c2) cout<<"Yay!"<<endl;
	cout<<"Sum of points a and b is point"<< c1<< endl;
	point npoint;
	cout<<"Please enter a point";
	cin>> npoint;
	cout << "You enter a point"<< npoint<<endl;
	return 0;
}


