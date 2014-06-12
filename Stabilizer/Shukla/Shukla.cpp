#include <iostream>
#include "Shukla.h"
#include "../../GraphGenerator.h"

using namespace std;

void Shukla::applyRules()
{
	// if node i and all of its neighbours are not in DS, then node i gets into DS
	// if node i and at least one of its neighbours are in DS, then node i gets out of DS
	ruleApplied = false;
	short neighboursInMds;
	for ( iter=nodeList->begin(); iter!=nodeList->end(); ++iter )
	{
		neighboursInMds = 0;
		vector<Node*>::iterator nIter;
		for (nIter=iter->getNeighborsAddress()->begin(); nIter!=iter->getNeighborsAddress()->end(); ++nIter)
		{
			if ( (*nIter)->getState() == 1 ) neighboursInMds++;
		}

		if ( iter->getState() == 0 && neighboursInMds == 0 )
		{
			cout << "Node" << iter->getId() << " gets into DS [Shukla Rule1]" << endl;
			iter->setState(1);
			incrementStepCount();
			ruleApplied = true;
		}
		else if ( iter->getState() == 1 && neighboursInMds > 0 )
		{
			cout << "Node" << iter->getId() << " gets out of DS [Shukla Rule 2]" << endl;
			iter->setState(0);
			incrementStepCount();
			ruleApplied = true;
		}
	}

	isStabilized = !ruleApplied;
}
