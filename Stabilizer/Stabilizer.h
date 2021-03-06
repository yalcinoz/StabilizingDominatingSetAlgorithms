#ifndef STABILIZER_H_
#define STABILIZER_H_

#include <vector>
#include "../Node.h"

#define OUT 0
#define IN 1
#define WAIT 2

class Stabilizer
{
protected:
	vector<Node>* nodeList;
	vector<Node>::iterator iter;
	int stepCount;
	short size;
	bool isStabilized;
	bool ruleApplied; // true if any rule is applied in one iteration

public:
	explicit Stabilizer(vector<Node>*);
	vector<Node>* getNodeList();
	int getStepCount();
	void setStepCount(int);
	void incrementStepCount();
	void checkForFailure();
	void generateDominatingSet();
	short getSize();
	virtual void applyRules() {};
	virtual ~Stabilizer() {}
};

#endif /* STABILIZER_H_ */
