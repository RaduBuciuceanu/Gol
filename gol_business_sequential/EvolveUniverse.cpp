#include "EvolveUniverse.h"

#include <EvolveGalaxy.h>
#include <GalaxyRepository.h>
#include <UniverseRepository.h>

EvolveUniverse::EvolveUniverse()
{
	_universeRepository = new UniverseRepository();
	_galaxyRepository = new GalaxyRepository();
	_evolveGalaxy = new EvolveGalaxy();
}

EvolveUniverse::~EvolveUniverse()
{
	delete _universeRepository;
	delete _galaxyRepository;
	delete _evolveGalaxy;
}

const Universe* EvolveUniverse::execute(Input input)
{
	for (const Galaxy* galaxy : _galaxyRepository->getAll())
	{
		_evolveGalaxy->execute(galaxy);
	}

	return _universeRepository->get();
}
