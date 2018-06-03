#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "observer.h"
#include <algorithm>
#include <vector>

class IsEqualTo final
{
public:
	explicit IsEqualTo(const ObserverPtr& observer) :
			observer { observer }
	{
	}

	bool operator()(const ObserverPtr& observerToCompare) {
		return observerToCompare->getId() == observer->getId();
	}

private:
	ObserverPtr observer;
};

class Subject
{
public:
	void addObserer(ObserverPtr& observerToAdd) {
		auto iter = std::find_if(begin(observers), end(observers),
				IsEqualTo(observerToAdd));
		if (iter == end(observers)) {
			observers.push_back(observerToAdd);
		}
	}

	void removeObserver(ObserverPtr& observerToRemove) {
		observers.erase(std::remove_if(begin(observers), end(observers),
				IsEqualTo(observerToRemove)), end(observers));
	}

	void displayAllObservers() const {
		std::cout << "[ ";
		for (const auto& observer : observers) {
			std::cout << observer->getName() << " ";
		}
		std::cout << "]" << std::endl;
	}

protected:
	void notifyAllObservers() const {
		for (const auto& observer : observers) {
			observer->update();
		}
	}

private:
	std::vector<ObserverPtr> observers;
};

#endif /* SUBJECT_H_ */
