#include "drawingprocessor.h"
#include "drawcirclecommand.h"
#include "drawrectanglecommand.h"
#include "undocommand.h"
#include "compositecommand.h"
#include "point.h"

void testSingleCommands()
{
	CommandProcessor commandProcessor;
	DrawingProcessor drawingProcessor;

	Point circleCenterPoint1{20, 20};
	double circleRadius1 = 10.0;
	CommandPtr drawCircleCommand1 = std::make_shared<DrawCircleCommand>(drawingProcessor, circleCenterPoint1, circleRadius1);
	commandProcessor.execute(drawCircleCommand1);

	Point circleCenterPoint2{25, 25};
	double circleRadius2 = 15.0;
	CommandPtr drawCircleCommand2 = std::make_shared<DrawCircleCommand>(drawingProcessor, circleCenterPoint2, circleRadius2);
	commandProcessor.execute(drawCircleCommand2);

	Point rectangleCenterPoint{30, 10};
	CommandPtr drawRectangleCommand = std::make_shared<DrawRectangleCommand>(drawingProcessor, rectangleCenterPoint, 5, 8);
	commandProcessor.execute(drawRectangleCommand);

	UndoCommand undo(commandProcessor);
	undo.execute();
	undo.execute();
}

int main()
{
	// testSingleCommands();

	auto macroRecorder = std::make_shared<CompositeCommand>();
	DrawingProcessor drawingProcessor;

	Point circleCenterPoint1{20, 20};
	double circleRadius1 = 10.0;
	CommandPtr drawCircleCommand1 = std::make_shared<DrawCircleCommand>(drawingProcessor, circleCenterPoint1, circleRadius1);
	macroRecorder->addCommand(drawCircleCommand1);

	Point circleCenterPoint2{25, 25};
	double circleRadius2 = 15.0;
	CommandPtr drawCircleCommand2 = std::make_shared<DrawCircleCommand>(drawingProcessor, circleCenterPoint2, circleRadius2);
	macroRecorder->addCommand(drawCircleCommand2);

	Point rectangleCenterPoint{30, 10};
	CommandPtr drawRectangleCommand = std::make_shared<DrawRectangleCommand>(drawingProcessor, rectangleCenterPoint, 5, 8);
	macroRecorder->addCommand(drawRectangleCommand);

	std::cout << "-- Execute commands in macro recorder --" << std::endl;
	macroRecorder->execute();

	std::cout << "-- Undo commands in macro recorder --" << std::endl;
	macroRecorder->undo();
}
