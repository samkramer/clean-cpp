#ifndef DRAWRECTANGLECOMMAND_H_
#define DRAWRECTANGLECOMMAND_H_

#include "command.h"
#include "drawingprocessor.h"

class DrawRectangleCommand: public UndoableCommand
{
public:
	DrawRectangleCommand(DrawingProcessor& receiver, const Point& centerPoint, const double length, const double width) :
			receiver(receiver), centerPoint(centerPoint), length(length), width(width)
	{
	}

	virtual void execute() override
	{
		receiver.drawRectangle(centerPoint, length, width);
	}

	virtual void undo() override
	{
		receiver.eraseRectangle(centerPoint, length, width);
	}

private:
	DrawingProcessor& receiver;
	const Point centerPoint;
	const double length;
	const double width;
};

#endif /* DRAWRECTANGLECOMMAND_H_ */
