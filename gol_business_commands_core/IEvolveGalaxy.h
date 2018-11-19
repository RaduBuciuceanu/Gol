#pragma once

#include "ICommand.h"

#include <Galaxy.h>

class IEvolveGalaxy : public ICommand<const Galaxy*, const Galaxy*>
{
public:
	virtual ~IEvolveGalaxy() override = default;
};
