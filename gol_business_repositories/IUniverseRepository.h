#pragma once

#include "Preprocessor.h"

#include <Universe.h>

class IUniverseRepository
{
public:
	virtual ~IUniverseRepository() = default;

	virtual const Universe* insert(const Universe* universe) = 0;

	virtual const Universe* get() const = 0;
};
