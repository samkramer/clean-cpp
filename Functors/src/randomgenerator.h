#ifndef RANDOMGENERATOR_H_
#define RANDOMGENERATOR_H_

#include <random>

template <typename T>
class RandomNumberGenerator {
public:
	RandomNumberGenerator() {
		mersenneTwisterEngine.seed(randomDevice());
	}

	T operator()() {
		return distribution(mersenneTwisterEngine);
	}

private:
	std::random_device randomDevice;
	std::uniform_int_distribution<T> distribution;
	std::mt19937_64 mersenneTwisterEngine;
};


#endif /* RANDOMGENERATOR_H_ */
