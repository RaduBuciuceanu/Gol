#pragma once

#include "ICommand.h"
#include "Input.h"

#include <Universe.h>

class IEvolveUniverse : public ICommand<Input, const Universe*>
{
public:
	virtual ~IEvolveUniverse() override = default;
};
