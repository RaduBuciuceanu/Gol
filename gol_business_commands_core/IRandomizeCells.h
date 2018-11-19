#pragma once

#include "ICommand.h"
#include "Input.h"
#include "Output.h"

class IRandomizeCells : public ICommand<Input, Output>
{
public:
	virtual ~IRandomizeCells() override = default;
};
