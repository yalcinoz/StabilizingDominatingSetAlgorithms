#ifndef GRAPHGENERATOR_H_
#define GRAPHGENERATOR_H_


#include <vector>
#include "Node.h"

using namespace std;

class GraphGenerator
{
private:
	vector<Node> nodeList;
	vector<Node>::iterator iter;

public:
	GraphGenerator();
	vector<Node>* getNodeListAddress();
	void createGraph();
	void createNodes();
	void setRandomNeighbors();
	void setRandomDominators();
	void appendToNodeList(Node);
	void printGraph();

	static const short NODECOUNT = 50; // [25, 50, 75, 100]
	static const short NEIGHCOUNT = 16; // [4, 8, 12, 16]
	static const short FAULT_PERCENTAGE = 10; // [5, 10, 15, 20]
	static const short DOMINATOR_CHANCE = 30; // percent chance to have a dominator (only necessary for minimal dominating set alg.)
};


#endif /* GRAPHGENERATOR_H_ */
