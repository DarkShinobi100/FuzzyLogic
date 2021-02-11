#include <fl/Headers.h>
#include <iostream>
using namespace fl;

int main()
{
	Engine* engine = new Engine();

	std::string status;
	if (not engine->isReady(&status))
		std::cout << "Engine is not ready" << std::endl << status << std::endl;

	//creating an input variable
	InputVariable* obstacle = new InputVariable;
	engine->addInputVariable(obstacle);

	//set values
	obstacle->setName("obstacle");
	obstacle->setRange(0.000, 1.000);
	
	//adding terms
	obstacle->addTerm(new Ramp("left", 1.000, 0.000));
	obstacle->addTerm(new Ramp("right", 0.000, 1.000));

	//creating an output variable
	OutputVariable* mSteer = new OutputVariable;
	engine->addOutputVariable(mSteer);
	mSteer->setName("mSteer");
	mSteer->setRange(0.000, 1.000);
	mSteer->setAggregation(new Maximum);
	mSteer->setDefuzzifier(new Centroid(100));
	mSteer->setDefaultValue(fl::nan);
	mSteer->addTerm(new Ramp("left", 1.000, 0.000));
	mSteer->addTerm(new Ramp("right", 0.000, 1.000));

	delete engine;
	return 0;
}