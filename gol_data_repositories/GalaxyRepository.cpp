#include "GalaxyRepository.h"

QList<const Galaxy*> GalaxyRepository::_galaxies = QList<const Galaxy*>();

const Galaxy* GalaxyRepository::insert(const Galaxy* galaxy)
{
	_galaxies.append(galaxy);
	return galaxy;
}

QList<const Galaxy*> GalaxyRepository::getAll() const
{
	return _galaxies;
}
