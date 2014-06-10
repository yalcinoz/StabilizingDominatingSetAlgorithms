#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "Stabilizer.h"
#include "../GraphGenerator.h"
#include "../Node.h"

using namespace std;

Stabilizer::Stabilizer(vector<Node>* list)
{
	srand((unsigned)time(0));
	nodeList = list;
	stepCount = 0;
	isStabilized = false;
	ruleApplied = false;
	size = 0;
}

vector<Node>* Stabilizer::getNodeList()
{
	return nodeList;
}

int Stabilizer::getStepCount()
{
	return stepCount;
}

void Stabilizer::setStepCount(int _stepCount)
{
	stepCount = _stepCount;
}

void Stabilizer::incrementStepCount()
{
	++stepCount;
}

void Stabilizer::checkForFailure()
{
	short rate = rand() % 100;
	if ( rate < 50 )
	{
		short randomNodeIndex = rand() % nodeList->size();
		Node* n = &nodeList->at(randomNodeIndex);
		vector<Node*>::iterator iter;
		for ( iter = n->getNeighborsAddress()->begin(); iter != n->getNeighborsAddress()->end(); ++iter )
		{
			vector<Node*>::iterator nIter;
			for ( nIter = (*iter)->getNeighborsAddress()->begin(); nIter != (*iter)->getNeighborsAddress()->end(); ++nIter )
			{
				if ( (*nIter)->getId() == n->getId() )
				{
					(*iter)->getNeighborsAddress()->erase( nIter );
					--nIter;
				}
			}
		}
	}
}

short Stabilizer::getSize()
{
	for (iter = nodeList->begin(); iter != nodeList->end(); ++iter)
	{
		if ( iter->getState() == 1 ) ++size;
	}

	return size;
}

void Stabilizer::generateDominatingSet()
{
	cout << "Dominating Set Stabilization Algorithm Is Starting" << endl;
	while ( !isStabilized )
	{
		//checkForFailure();
		applyRules();
	}
	cout << "Dominating Set Stabilization Algorithm Ended In " << getStepCount() << " Steps And " << getSize() << " Nodes" << endl;
}
