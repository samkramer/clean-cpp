#ifndef DRAWINGPROCESSOR_H_
#define DRAWINGPROCESSOR_H_

#include <iostream>
#include "point.h"

class DrawingProcessor
{
public:
	void drawCircle(const Point& centerPoint, const double radius) {
		std::cout << "Draw Circle: " << centerPoint << ", radius=" << radius << std::endl;
	}

	void eraseCircle(const Point& centerPoint, const double radius) {
		std::cout << "Erase Circle: " << centerPoint << ", radius=" << radius << std::endl;
	}
};

#endif /* DRAWINGPROCESSOR_H_ */
