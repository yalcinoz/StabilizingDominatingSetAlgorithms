#ifndef SHUKLA_H_
#define SHUKLA_H_

#include "../Stabilizer.h"

class Shukla: public Stabilizer
{
	using Stabilizer::Stabilizer;

public:
	void applyRules();
	~Shukla() {}
};


#endif /* SHUKLA_H_ */
