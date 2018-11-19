#pragma once

#include "ICommand.h"

#include <Cell.h>

class IEvolveCell : public ICommand<const Cell*, const Cell*>
{
public:
	virtual ~IEvolveCell() override = default;
};
