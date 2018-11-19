#pragma once

#include "Preprocessor.h"

#include <ICellRepository.h>
#include <IEvolveCell.h>

class GOL_BUSINESS_COMMANDS_API EvolveCell : public IEvolveCell
{
private:
	ICellRepository* _cellRepository;

public:
	explicit EvolveCell();

	virtual ~EvolveCell() override;

	const Cell* execute(const Cell* cell) override;
};
