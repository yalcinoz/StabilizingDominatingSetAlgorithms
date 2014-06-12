#include <cstdlib>
#include <iostream>
#include <ctime>
#include "GraphGenerator.h"

using namespace std;

GraphGenerator::GraphGenerator()
{
	srand((unsigned)time(0));
}

vector<Node>* GraphGenerator::getNodeListAddress()
{
	return &nodeList;
}

void GraphGenerator::createGraph()
{
	createNodes();
	setRandomNeighbors();
	setRandomDominators();
	printGraph();
}

void GraphGenerator::createNodes()
{
	for (short i=0; i<GraphGenerator::NODECOUNT; i++)
	{
		Node n;
		n.setId(i);
		n.setState( rand() % 2 );
		GraphGenerator::appendToNodeList(n);
	}
}

void GraphGenerator::setRandomNeighbors()
{
	// each node has neighbours based on their IDs.
	// so if node 8 has 4 neighbours, they're nodes with IDs 6, 7, 9 and 10
	short neighbourIndex;
	for (iter = nodeList.begin(); iter != nodeList.end(); ++iter)
	{
		neighbourIndex = iter->getId();
		for (short i=1; i <= GraphGenerator::NEIGHCOUNT; i++)
		{
			neighbourIndex = i % 2 == 1 ? neighbourIndex - i : neighbourIndex + i;
			if ( neighbourIndex < 0 ) neighbourIndex += GraphGenerator::NODECOUNT;
			if ( neighbourIndex >= GraphGenerator::NODECOUNT ) neighbourIndex -= GraphGenerator::NODECOUNT;
			Node* n = &nodeList.at(neighbourIndex);
			iter->setNeighbor(n);
		}
	}
}

void GraphGenerator::setRandomDominators()
{
	// generates random dominators by chance
	for (iter = nodeList.begin(); iter != nodeList.end(); ++iter)
	{
		short randNum = rand() % 100;
		if ( randNum < GraphGenerator::DOMINATOR_CHANCE )
		{
			short randNeighborIndex = rand() % GraphGenerator::NEIGHCOUNT;
			iter->setDominator( &nodeList.at(randNeighborIndex) );
		}
	}
}

void GraphGenerator::appendToNodeList(Node _node)
{
	nodeList.push_back(_node);
}

void GraphGenerator::printGraph()
{
	for (iter = nodeList.begin(); iter != nodeList.end(); ++iter)
	{
		cout << "ID: " << iter->getId() << "| State: " << iter->getState() << " | ";
		iter->printNeighbors();
	}
}


