#ifndef NODE_H_
#define NODE_H_

#include <vector>

using namespace std;

class Node
{
private:
	short id;
	short state;
	bool isDeleted; // true if node is removed from the graph
	Node* dominator;
	vector<Node*> neighbors;
	vector<Node*>::iterator iter;

public:
	Node();
	void setId(short);
	short getId();
	void setState(short);
	short getState();
	void setIsDeleted(bool);
	bool getIsDeleted();
	void setDominator(Node*);
	Node* getDominator();
	void setNeighbor(Node*);
	Node* getNeighbor(short);
	vector<Node*>* getNeighborsAddress();
	void printNeighbors();
};

#endif /* NODE_H_ */
