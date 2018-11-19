#include "EvolveGalaxy.h"

#include <CellRepository.h>
#include <EvolveCell.h>

EvolveGalaxy::EvolveGalaxy()
{
	_cellRepository = new CellRepository();
	_evolveCell = new EvolveCell();
}

EvolveGalaxy::~EvolveGalaxy()
{
	delete _cellRepository;
	delete _evolveCell;
}

const Galaxy* EvolveGalaxy::execute(const Galaxy* galaxy)
{
	QList<const Cell*> cells = _cellRepository->getChilds(galaxy);

	for (const Cell* cell : cells)
	{
		_evolveCell->execute(cell);
	}

	return galaxy;
}
