#include "GraphGenerator.h"
#include "Stabilizer/DominatingSet/DominatingSetStabilizer.h"
#include "Stabilizer/MinimalDominatingSet/MinimalDominatingSetStabilizer.h"
#include "Stabilizer/Shukla/Shukla.h"
#include "Stabilizer/Ikeda/Ikeda.h"
#include "Stabilizer/Turau/Turau.h"

int main(int argc, char** argv)
{

	GraphGenerator gen;
	gen.createGraph();

	//DominatingSetStabilizer s( gen.getNodeListAddress() );
	//MinimalDominatingSetStabilizer s( gen.getNodeListAddress() );
	//Shukla s( gen.getNodeListAddress() );
	//Ikeda s( gen.getNodeListAddress() );
	Turau s( gen.getNodeListAddress() );
	s.generateDominatingSet();


	return 1;
}
