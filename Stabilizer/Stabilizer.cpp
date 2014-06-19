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
	// minimum average step count is 9 (except Dominating Set alg.)
	// so in step count 3, 6 and 9, algorithm will fail some nodes based on fault percentage
	short nodeCountToFail = 1 + ( (GraphGenerator::NODECOUNT - 1) * GraphGenerator::FAULT_PERCENTAGE / 100);
	short failPerRound = 0;

	if ( nodeCountToFail < 3 )
	{
		if ( stepCount == 3 ) failPerRound = nodeCountToFail;
	}
	else
	{
		if ( stepCount == 3 || stepCount == 6 || stepCount == 9)
		{
			// e.g. if 5 nodes to fail, first two rounds only 1 node fails, 3. round rest of the nodes (3) fail.
			failPerRound = nodeCountToFail / 3;
			if ( stepCount == 9 ) failPerRound = nodeCountToFail - ( 2 * failPerRound );
		}
	}

	if ( failPerRound != 0 )
	{
		for ( int i = 0; i < failPerRound; i++)
		{
			// remove a random node which is not deleted before
			short randomNodeIndex = rand() % nodeList->size();
			Node* n = &nodeList->at(randomNodeIndex);
			if ( n->getIsDeleted() ) --i;
			else n->setIsDeleted(true);
		}
		cout << failPerRound << " random nodes failed" << endl;
	}
}

short Stabilizer::getSize()
{
	size = 0;
	for (iter = nodeList->begin(); iter != nodeList->end(); ++iter)
	{
		if ( iter->getState() == IN && iter->getIsDeleted() == false ) ++size;
	}

	return size;
}

void Stabilizer::generateDominatingSet()
{
	// main function to create a dominating set
	cout << "Dominating Set Stabilization Algorithm Is Starting" << endl;
	while ( !isStabilized )
	{
		applyRules();
	}
	cout << "Dominating Set Stabilization Algorithm Ended In " << getStepCount() << " Steps And " << getSize() << " Nodes" << endl;
}
