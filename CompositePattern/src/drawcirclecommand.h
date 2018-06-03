#ifndef DRAWCIRCLECOMMAND_H_
#define DRAWCIRCLECOMMAND_H_

#include "command.h"
#include "drawingprocessor.h"

class DrawCircleCommand : public UndoableCommand
{
public:
	DrawCircleCommand(DrawingProcessor& receiver, const Point& centerPoint, const double radius)
: receiver(receiver), centerPoint(centerPoint), radius(radius) {}

	virtual void execute() override {
		receiver.drawCircle(centerPoint, radius);
	}

	virtual void undo() override {
		receiver.eraseCircle(centerPoint, radius);
	}

private:
	DrawingProcessor& receiver;
	const Point centerPoint;
	const double radius;
};

#endif /* DRAWCIRCLECOMMAND_H_ */
