#include "InitializeUniverse.h"

#include <Cell.h>

InitializeUniverse::InitializeUniverse()
{
	_universeRepository = new UniverseRepository();
}

InitializeUniverse::~InitializeUniverse()
{
	delete _universeRepository;
}

const Universe* InitializeUniverse::execute(int input)
{
	auto universe = new Universe{input, input};
	return _universeRepository->insert(universe);
}
