#pragma once

#include "ICommand.h"
#include "Output.h"
#include "Preprocessor.h"

class IInitializeGalaxies : public ICommand<int, Output>
{
public:
	virtual ~IInitializeGalaxies() override = default;
};
