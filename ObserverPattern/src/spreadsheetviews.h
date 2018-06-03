#ifndef SPREADSHEETVIEWS_H_
#define SPREADSHEETVIEWS_H_

#include "observer.h"
#include "spreadsheetmodel.h"

class TableView : public Observer
{
public:
	explicit TableView(SpreadsheetModel& model_) : model{model_} { }

	virtual int getId() override {
		return 1;
	}

	virtual void update() override {
		std::cout << "Update TableView" << std::endl;
	}

	virtual std::string getName() const {
		return "TableView";
	}

private:
	SpreadsheetModel& model;
};

class BarChartView : public Observer
{
public:
	explicit BarChartView(SpreadsheetModel& model_) : model{model_} { }

	virtual int getId() override {
		return 2;
	}

	virtual void update() override {
		std::cout << "Update BarChartView" << std::endl;
	}

	virtual std::string getName() const {
		return "BarChartView";
	}

private:
	SpreadsheetModel& model;
};

class PieChartView : public Observer
{
public:
	explicit PieChartView(SpreadsheetModel& model_) : model{model_} { }

	virtual int getId() override {
		return 3;
	}

	virtual void update() override {
		std::cout << "Update PieChartView" << std::endl;
	}

	virtual std::string getName() const {
		return "PieChartView";
	}

private:
	SpreadsheetModel& model;
};


#endif /* SPREADSHEETVIEWS_H_ */
