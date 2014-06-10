#include <iostream>
#include "../../GraphGenerator.h"
#include "DominatingSetStabilizer.h"

using namespace std;

void DominatingSetStabilizer::applyRules()
{
	ruleApplied = false; // if any rule is applied to at least one of the nodes
	// if a node's state is equal to all of its neighbours' state, then node changes state
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		bool statesEqual = true;
		vector<Node*>::iterator nIter;
		for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
		{
			if ( (*nIter)->getState() != iter->getState() ) statesEqual = false;
		}

		if ( statesEqual )
		{
			short newState = iter->getState() == IN ? OUT : IN;
			cout << "Node" << iter->getId() << " transitioned state from " << iter->getState() << " to " << newState << endl;
			iter->setState(newState);
			incrementStepCount();
			ruleApplied = true;
		}
	}

	isStabilized = !ruleApplied;
}
