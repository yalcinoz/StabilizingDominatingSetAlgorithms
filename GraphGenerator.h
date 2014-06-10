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
	void appendToNodeList(Node);
	void printGraph();

	static const int NODECOUNT = 50; // [25, 50, 75, 100]
	static const int NEIGHCOUNT = 8; // [4, 8, 12, 16]
	static const int FAULT_PERCENTAGE = 5; // [5, 10, 15, 20]
};


#endif /* GRAPHGENERATOR_H_ */
