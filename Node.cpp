#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
	id = NULL;
	state = NULL;
	dominator = NULL;
	isDeleted = false;
}

void Node::setId(short _id)
{
	id = _id;
}

short Node::getId()
{
	return id;
}

void Node::setState(short s)
{
	state = s;
}

short Node::getState()
{
	return state;
}

void Node::setIsDeleted(bool _isDeleted)
{
	isDeleted = _isDeleted;
}

bool Node::getIsDeleted()
{
	return isDeleted;
}

void Node::setDominator(Node* n)
{
	dominator = n;
}

Node* Node::getDominator()
{
	return dominator;
}

void Node::setNeighbor(Node* n)
{
	neighbors.push_back(n);
}

Node* Node::getNeighbor(short index)
{
	return neighbors.at(index);
}

vector<Node*>* Node::getNeighborsAddress()
{
	return &neighbors;
}

void Node::printNeighbors()
{
	cout << "Neighbors: ";
	for (iter = neighbors.begin(); iter != neighbors.end(); ++iter)
	{
		if ( (*iter)->getIsDeleted() == false ) cout << (*iter)->getId() << " ";
	}
	cout << endl;
}
