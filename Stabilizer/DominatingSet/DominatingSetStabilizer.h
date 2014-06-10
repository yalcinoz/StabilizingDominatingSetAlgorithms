#ifndef DOMINATINGSETSTABILIZER_H_
#define DOMINATINGSETSTABILIZER_H_

#include "../Stabilizer.h"

class DominatingSetStabilizer: public Stabilizer
{
	using Stabilizer::Stabilizer;

public:
	void applyRules();
	~DominatingSetStabilizer() {}
};


#endif /* DOMINATINGSETSTABILIZER_H_ */
