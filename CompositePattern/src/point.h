#ifndef POINT_H_
#define POINT_H_

#include <ostream>

class Point
{
public:
	Point() : _x(0.0), _y(0.0) {}
	Point(double x, double y) : _x(x), _y(y) {}
	Point(const Point& p) : _x(p._x), _y(p._y) {}

	double getX() const { return _x; }
	double getY() const { return _y; }

private:
	double _x;
	double _y;
};

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "(" << point.getX() << ", " << point.getY() << ")";
	return os;
}

#endif /* POINT_H_ */
