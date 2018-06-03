#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <memory>
#include <string>

class Observer
{
public:
	virtual ~Observer() = default;
	virtual int getId() = 0;
	virtual void update() = 0;
	virtual std::string getName() const = 0;
};

using ObserverPtr = std::shared_ptr<Observer>;

#endif /* OBSERVER_H_ */
