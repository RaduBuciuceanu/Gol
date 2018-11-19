#pragma once

#include "Preprocessor.h"

#include <ICellRepository.h>
#include <IEvolveCell.h>
#include <IEvolveGalaxy.h>

class GOL_BUSINESS_SEQUENTIAL_API EvolveGalaxy : public IEvolveGalaxy
{
private:
	ICellRepository* _cellRepository;
	IEvolveCell* _evolveCell;

public:
	EvolveGalaxy();

	virtual ~EvolveGalaxy() override;

	const Galaxy* execute(const Galaxy* galaxy) override;
};
