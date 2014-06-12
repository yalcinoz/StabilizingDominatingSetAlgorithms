#ifndef TURAU_H_
#define TURAU_H_

#include "../Stabilizer.h"

class Turau: public Stabilizer
{
	using Stabilizer::Stabilizer;

public:
	void applyRules();
	void applyRule1();
	void applyRule2();
	void applyRule3();
	void applyRule4();
	~Turau() {}
};

#endif /* TURAU_H_ */
