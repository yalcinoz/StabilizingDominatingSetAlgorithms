#include <iostream>
#include "Turau.h"
#include "../../GraphGenerator.h"

using namespace std;

void Turau::applyRules()
{
	ruleApplied = false;
	Turau::applyRule1();
	Turau::applyRule2();
	Turau::applyRule3();
	Turau::applyRule4();
	isStabilized = !ruleApplied;
}

void Turau::applyRule1()
{
	// if node i and all of its neighbours are not in MDS, then node i gets into WAIT state
	short neighboursInDs;
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == OUT && iter->getIsDeleted() == false )
		{
			neighboursInDs = 0;
			vector<Node*>::iterator nIter;
			for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getState() == IN && (*nIter)->getIsDeleted() == false ) neighboursInDs++;
			}

			if ( neighboursInDs == 0 )
			{
				cout << "Node" << iter->getId() << " gets into WAIT state [Turau Rule 1]" << endl;
				iter->setState(WAIT);
				incrementStepCount();
				ruleApplied = true;
			}
		}
	}
}

void Turau::applyRule2()
{
	// if node i is in WAIT state and any of its neighbours' state becomes IN, then node i gets into OUT state
	short neighboursInDs;
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == WAIT && iter->getIsDeleted() == false )
		{
			neighboursInDs = 0;
			vector<Node*>::iterator nIter;
			for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getState() == IN && (*nIter)->getIsDeleted() == false ) neighboursInDs++;
			}

			if ( neighboursInDs > 0 )
			{
				cout << "Node" << iter->getId() << " gets into OUT state [Turau Rule 2]" << endl;
				iter->setState(OUT);
				incrementStepCount();
				ruleApplied = true;
			}
		}
	}
}

void Turau::applyRule3()
{
	// if node i is in WAIT state, none of its neighbours are in IN state and no neighbours with lower ID are in WAIT state
	// then node i gets into IN state
	short neighboursInDs;
	short neighboursInWaitWithLowerId;
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == WAIT && iter->getIsDeleted() == false )
		{
			neighboursInDs = 0;
			neighboursInWaitWithLowerId = 0;
			vector<Node*>::iterator nIter;
			for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getIsDeleted() == false )
				{
					if ( (*nIter)->getState() == IN ) neighboursInDs++;
					if ( (*nIter)->getState() == WAIT && (*nIter)->getId() < iter->getId() )
						neighboursInWaitWithLowerId++;
				}
			}

			if ( neighboursInDs == 0 && neighboursInWaitWithLowerId == 0 )
			{
				cout << "Node" << iter->getId() << " gets into IN state [Turau Rule 3]" << endl;
				iter->setState(IN);
				incrementStepCount();
				ruleApplied = true;
			}
		}
	}
}

void Turau::applyRule4()
{
	// if node i is in IN state and at least one of its neighbours also gets into IN state
	// node i changes its state to OUT
	short neighboursInDs;
	for ( iter = nodeList->begin(); iter != nodeList->end(); ++iter )
	{
		if ( iter->getState() == IN && iter->getIsDeleted() == false )
		{
			neighboursInDs = 0;
			vector<Node*>::iterator nIter;
			for ( nIter = iter->getNeighborsAddress()->begin(); nIter != iter->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getState() == IN && (*nIter)->getIsDeleted() == false ) neighboursInDs++;
			}

			if ( neighboursInDs > 0 )
			{
				cout << "Node" << iter->getId() << " gets into IN state [Turau Rule 4]" << endl;
				iter->setState(OUT);
				incrementStepCount();
				ruleApplied = true;
			}
		}
	}
}
