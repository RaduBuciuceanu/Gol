#pragma once

#include "Preprocessor.h"

#include <ICellRepository.h>
#include <IInitializeCells.h>
#include <IUniverseRepository.h>

class GOL_BUSINESS_SEQUENTIAL_API InitializeCells : public IInitializeCells
{
private:
	ICellRepository* _cellRepository;
	IUniverseRepository* _universeRepository;

public:
	explicit InitializeCells();

	virtual ~InitializeCells() override;

	Output execute(Input input) override;
};
