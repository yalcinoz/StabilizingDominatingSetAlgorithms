#ifndef NODE_H_
#define NODE_H_

#include <vector>

using namespace std;

class Node
{
private:
	short id;
	short state;
	Node* dominator;
	vector<Node*> neighbors;
	vector<Node*>::iterator iter;

public:
	Node();
	void setId(short);
	short getId();
	void setState(short);
	short getState();
	void setDominator(Node*);
	Node* getDominator();
	void setNeighbor(Node*);
	Node* getNeighbor(short);
	vector<Node*>* getNeighborsAddress();
	void printNeighbors();
};

#endif /* NODE_H_ */
