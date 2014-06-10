#include "GraphGenerator.h"
#include "Stabilizer/DominatingSet/DominatingSetStabilizer.h"
#include "Stabilizer/MinimalDominatingSet/MinimalDominatingSetStabilizer.h"

int main(int argc, char** argv)
{

	GraphGenerator gen;
	gen.createGraph();

	//DominatingSetStabilizer s( gen.getNodeListAddress() );
	MinimalDominatingSetStabilizer s( gen.getNodeListAddress() );
	s.generateDominatingSet();


	return 1;
}
