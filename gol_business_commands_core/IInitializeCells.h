#pragma once

#include "ICommand.h"
#include "Input.h"
#include "Output.h"
#include "Preprocessor.h"

class IInitializeCells : public ICommand<Input, Output>
{
public:
	virtual ~IInitializeCells() override = default;
};
