#ifndef SWITCHABLE_H_
#define SWITCHABLE_H_

class Switchable
{
public:
	virtual ~Switchable() = default;
	virtual void on() = 0;
	virtual void off() = 0;
};

#endif /* SWITCHABLE_H_ */
