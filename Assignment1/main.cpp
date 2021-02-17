#include <iostream>

class point{
	public:
		point(double inital_X = 0.0, double inital_y = 0.0);
		void shift( double x_value, double y_value);
		void rotate90();
		//const getter member function
		double get_x() const{return x; }
		double get_y() const{return y; }
		friend std::istream& operator >>(std::istream& ins, point& target);
	private:
		double x, y;

};

//nonmember functions
double distance (const point& point1, const point& point2);
point midpoint(const point& point1, const point& point2);
point operator +(const point& point1, const point& point2);
bool operator ==(const point& point1, const point& point2);
bool operator !=(const point& point1, const point& point2);
std::ostream& operator <<(std:ostream & outs, const point& source);


