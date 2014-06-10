#ifndef MINIMALDOMINATINGSETSTABILIZER_H_
#define MINIMALDOMINATINGSETSTABILIZER_H_

#include "../Stabilizer.h"

class MinimalDominatingSetStabilizer: public Stabilizer
{
	using Stabilizer::Stabilizer;

public:
	void applyRules();
	void applyMembershipRule1();
	void applyMembershipRule2();
	void applyPointerRule1();
	void applyPointerRule2();
	void applyPointerRule3();
	~MinimalDominatingSetStabilizer() {}
};

#endif /* MINIMALDOMINATINGSETSTABILIZER_H_ */
