#include "InitializeGalaxies.h"

#include <GalaxyRepository.h>
#include <Universe.h>
#include <UniverseRepository.h>

InitializeGalaxies::InitializeGalaxies()
{
	_galaxyRepository = new GalaxyRepository();
	_universeRepository = new UniverseRepository();
}

InitializeGalaxies::~InitializeGalaxies()
{
	delete _galaxyRepository;
	delete _universeRepository;
}

Output InitializeGalaxies::execute(int count)
{
	for (int index = 0; index < count; index++)
	{
		int length = getGalaxyLength(count, index == count - 1);
		auto galaxy = new Galaxy{index, length};
		_galaxyRepository->insert(galaxy);
	}

	return Output::nothing();
}

int InitializeGalaxies::getGalaxyLength(int requiredCount, bool isLastOne) const
{
	const Universe* universe = _universeRepository->get();
	int length = universe->length / requiredCount;

	if (isLastOne)
	{
		length += universe->length % requiredCount;
	}

	return length;
}
