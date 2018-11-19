#pragma once

#include "Preprocessor.h"

#include <ICellRepository.h>
#include <IRandomizeCells.h>

class GOL_BUSINESS_SEQUENTIAL_API RandomizeCells : public IRandomizeCells
{
private:
	ICellRepository* _cellRepository;

public:
	explicit RandomizeCells();

	virtual ~RandomizeCells() override;

	Output execute(Input input) override;
};
