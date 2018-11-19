#include "UniverseRepository.h"

Universe* UniverseRepository::_universe = nullptr;

const Universe* UniverseRepository::insert(const Universe* universe)
{
	_universe = const_cast<Universe*>(universe);
	return universe;
}

const Universe* UniverseRepository::get() const
{
	return _universe;
}
