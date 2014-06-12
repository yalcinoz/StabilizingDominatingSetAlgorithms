#include <iostream>
#include "Ikeda.h"
#include "../../GraphGenerator.h"

using namespace std;

void Ikeda::applyRules()
{
	ruleApplied = false;
	applyIkedaRule1();
	applyIkedaRule2();
	isStabilized = !ruleApplied;
}

void Ikeda::applyIkedaRule1()
{
	// if node i and all of its neighbours are not in MDS, then node i gets into MDS
	short neighboursInMds;
	for ( iter=nodeList->begin(); iter!=nodeList->end(); ++iter )
	{
		neighboursInMds = 0;
		vector<Node*>::iterator nIter;
		for ( nIter=iter->getNeighborsAddress()->begin(); nIter!=iter->getNeighborsAddress()->end(); ++nIter )
		{
			if ( (*nIter)->getState() == 1 ) neighboursInMds++;
		}

		if ( iter->getState() == 0 && neighboursInMds == 0 )
		{
			cout << "Node" << iter->getId() << " gets into DS [Ikeda Rule 1]" << endl;
			iter->setState(1);
			incrementStepCount();
			ruleApplied = true;
		}
	}
}

void Ikeda::applyIkedaRule2()
{
	// if node i and at least one of its neighbours are in DS
	// and node i does not have the lowest id, then node i gets out of DS
	short neighboursWithLowerIdInMds;
	for ( iter=nodeList->begin(); iter!=nodeList->end(); ++iter )
	{
		neighboursWithLowerIdInMds = 0;
		vector<Node*>::iterator nIter;
		for ( nIter=iter->getNeighborsAddress()->begin(); nIter!=iter->getNeighborsAddress()->end(); ++nIter )
		{
			if ( (*nIter)->getState() == 1 && (*nIter)->getId() < iter->getId() ) neighboursWithLowerIdInMds++;
		}

		if ( iter->getState() == 1 && neighboursWithLowerIdInMds > 0 )
		{
			cout << "Node" << iter->getId() << " gets out of DS [Ikeda Rule 2]" << endl;
			iter->setState(0);
			incrementStepCount();
			ruleApplied = true;
		}
	}
}
