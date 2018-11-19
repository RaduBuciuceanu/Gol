#pragma once

#include "ICommand.h"
#include "Preprocessor.h"

#include <Universe.h>

class IInitializeUniverse : public ICommand<int, const Universe*>
{
public:
	virtual ~IInitializeUniverse() override = default;
};
