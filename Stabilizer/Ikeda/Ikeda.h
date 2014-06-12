#ifndef IKEDA_H_
#define IKEDA_H_

#include "../Stabilizer.h"

class Ikeda: public Stabilizer
{
	using Stabilizer::Stabilizer;

public:
	void applyRules();
	void applyIkedaRule1();
	void applyIkedaRule2();
	~Ikeda() {}
};

#endif /* IKEDA_H_ */
