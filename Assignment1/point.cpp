#include <iostream>
#include "point.hpp"
#include <cmath>
using namespace std;

namespace ni_point{
	point::point (double inital_x, double inital_y){
		x = inital_x;
		y = inital_y;
	}
	void point::shift(double x_amount, double y_amount){
		x += x_amount;
		y += y_amount;
	}
	void point::rotate90(){
		double x_value;
		double y_value;
		x_value = y;
		y_value =-x;
		x = x_value;
		y = y_value;
	} 
	//friend function
	istream& operator >>(istream& ins, point& target){
		ins >> target.x >> target.y;
		return ins;
	}
	
	double distance(const point& p1, const point& p2){
		double a, b, c;
		a = p1.get_x() - p2.get_x(); 
		b = p1.get_y() - p2.get_y();
		c = a*a + b*b;
		return sqrt(c); 
	}
	point middle(const point& p1, const point& p2){
		double x_mid;  
		double y_mid;
		x_mid = (p1.get_x() + p2.get_x())/2;
		y_mid = (p1.get_y() + p2.get_y())/2;
		point midpoint(x_mid, y_mid);
		return midpoint;		
	}
	point operator +(const point& p1, const point& p2){
		double x_sum, y_sum;
		x_sum = (p1.get_x() + p2.get_x());
		y_sum = (p1.get_y() + p2.get_y());
		point sum(x_sum, y_sum);
		return sum;
	}
	bool operator == (const point& p1, const point& p2){
		return
			(p1.get_x() == p2.get_x())
			&&
			(p1.get_y() == p2.get_y());
	}
	bool operator != (const point& p1, const point& p2){
		return !(p1 == p2);
	}
	ostream& operator << (ostream & outs, const point& source){
		outs << "(" << source.get_x() << ","<< source.get_y()<<")";
		return outs;
	}
}