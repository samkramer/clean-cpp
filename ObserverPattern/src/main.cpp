#include <iostream>
#include "spreadsheetmodel.h"
#include "spreadsheetviews.h"

int main()
{
	SpreadsheetModel model;

	ObserverPtr observer1 = std::make_shared<TableView>(model);
	model.addObserer(observer1);

	ObserverPtr observer2 = std::make_shared<BarChartView>(model);
	model.addObserer(observer2);

	ObserverPtr observer3 = std::make_shared<PieChartView>(model);
	model.addObserer(observer3);

	model.displayAllObservers();

	model.changeCellValue("A", 1, 42);
	model.changeCellValue("B", 2, 23.1);

	model.removeObserver(observer1);
	model.displayAllObservers();

	model.changeCellValue("C", 3, 3.14159);
}
