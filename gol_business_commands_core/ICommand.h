#pragma once

#include "Preprocessor.h"

template <class TInput, class TOutput>
class ICommand
{
public:
	virtual ~ICommand() = default;

	virtual TOutput execute(TInput input) = 0;
};
