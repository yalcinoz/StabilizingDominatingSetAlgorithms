#include <iostream>
#include "MinimalDominatingSetStabilizer.h"
#include "../../GraphGenerator.h"

using namespace std;

void MinimalDominatingSetStabilizer::applyRules()
{
	ruleApplied = false;
	MinimalDominatingSetStabilizer::applyMembershipRule1();
	MinimalDominatingSetStabilizer::applyMembershipRule2();
	MinimalDominatingSetStabilizer::applyPointerRule1();
	MinimalDominatingSetStabilizer::applyPointerRule2();
	MinimalDominatingSetStabilizer::applyPointerRule3();
	isStabilized = !ruleApplied;
}

void MinimalDominatingSetStabilizer::applyMembershipRule1()
{
	// if node i and all its neighbors are not in MDS, i enters MDS
	bool candidate;
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == 0 )
		{
			candidate = true;
			vector<Node*>::iterator nIter;
			for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getState() != 0 ) candidate = false;
			}

			if ( candidate )
			{
				iter->setState(1);
				cout << "Node" << iter->getId() << " gets into MDS [Membership Rule 1]" << endl;
				incrementStepCount();
				ruleApplied = true;
			}
		}
	}
}

void MinimalDominatingSetStabilizer::applyMembershipRule2()
{
	// If a node is in MDS and also at least one of its neighbors is in MDS,
	// then if node does not dominate any of its neighbours, it gets out of MDS
	bool isDominator;
	bool neighboursInMds;
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == 1 )
		{
			isDominator = false;
			neighboursInMds = false;
			vector<Node*>::iterator nIter;
			for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getState() == 1 ) neighboursInMds = true;
				if ( (*nIter)->getDominator() != NULL && (*nIter)->getDominator()->getId() == iter->getId() )
					isDominator = true;
			}

			if ( neighboursInMds && !isDominator )
			{
				iter->setState(0);
				cout << "Node" << iter->getId() << " gets out of MDS [Membership Rule 2]" << endl;
				incrementStepCount();
				ruleApplied = true;
			}
		}
	}
}

void MinimalDominatingSetStabilizer::applyPointerRule1()
{
	// if node i is in MDS and also its pointer is not NULL, then it sets its pointer to NULL
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == 1 && iter->getDominator() != NULL )
		{
			iter->setDominator( NULL );
			cout << "Node" << iter->getId() << " is in MDS, so clearing its dominator [Pointer Rule 1]" << endl;
			incrementStepCount();
			ruleApplied = true;
		}
	}
}

void MinimalDominatingSetStabilizer::applyPointerRule2()
{
	// if node i is not in MDS and exactly one of its neighbours is in MDS
	// then if node i's pointer is not pointing to it, node i's pointer points to its neighbour in MDS
	short neighbourCountInMds;
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == 0 )
		{
			neighbourCountInMds = 0;
			Node* neighbour;
			vector<Node*>::iterator nIter;
			for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getState() == 1 )
				{
					neighbourCountInMds++;
					neighbour = *nIter;
				}
			}

			if ( neighbourCountInMds == 1 && ( iter->getDominator() == NULL || ( iter->getDominator() != NULL && iter->getDominator()->getId() != neighbour->getId() ) ) )
			{
				iter->setDominator( neighbour );
				cout << "Node" << iter->getId() << " is pointing to only neighbour in MDS: Node" << neighbour->getId() << " [Pointer Rule 2]" << endl;
				incrementStepCount();
				ruleApplied = true;
			}
		}
	}
}

void MinimalDominatingSetStabilizer::applyPointerRule3()
{
	// if node i is not in MDS but more than one of its neighbours are in MDS,
	// then if node i's pointer is not NULL, it sets its pointer to NULL
	short neighbourCountInMds;
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == 0 )
		{
			neighbourCountInMds = 0;
			vector<Node*>::iterator nIter;
			for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getState() == 1 )
					neighbourCountInMds++;
			}
			if ( neighbourCountInMds > 1 && iter->getDominator() != NULL )
			{
				iter->setDominator( NULL );
				cout << "Node" << iter->getId() << " is clearing its pointer as there are multiple neighbours in MDS [Pointer Rule 3]" << endl;
				incrementStepCount();
				ruleApplied = true;
			}
		}
	}
}
