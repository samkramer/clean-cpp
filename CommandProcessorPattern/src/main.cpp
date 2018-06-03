#include "drawingprocessor.h"
#include "drawcirclecommand.h"
#include "undocommand.h"

int main()
{
	CommandProcessor cmdProcessor;
	UndoCommand undo(cmdProcessor);

	DrawingProcessor receiver;

	UndoableCommandPtr drawCircleCmd1 = std::make_shared<DrawCircleCommand>(receiver, Point(1, 2), 5.0);
	cmdProcessor.execute(drawCircleCmd1);

	UndoableCommandPtr drawCircleCmd2 = std::make_shared<DrawCircleCommand>(receiver, Point(3, 4), 6.5);
	cmdProcessor.execute(drawCircleCmd2);

	undo.execute();

	UndoableCommandPtr drawCircleCmd3 = std::make_shared<DrawCircleCommand>(receiver, Point(5, 6), 5.0);
	cmdProcessor.execute(drawCircleCmd3);

	undo.execute();
	undo.execute();
}
