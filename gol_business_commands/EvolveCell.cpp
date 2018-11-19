#include "EvolveCell.h"

#include <CellRepository.h>

EvolveCell::EvolveCell()
{
	_cellRepository = new CellRepository();
}

EvolveCell::~EvolveCell()
{
	delete _cellRepository;
}

const Cell* EvolveCell::execute(const Cell* cell)
{
	QList<const Cell*> aliveNeighbors = _cellRepository->getAliveNeighbors(cell);
	QList<const Cell*> deadNeighbors = _cellRepository->getDeadNeighbors(cell);

	if (cell->value && aliveNeighbors.size() < 2)
	{
		const_cast<Cell*>(cell)->value = (false);
	}
	else if (cell->value && aliveNeighbors.size() > 3)
	{
		const_cast<Cell*>(cell)->value = (false);
	}
	else if (!cell->value && deadNeighbors.size() >= 3)
	{
		const_cast<Cell*>(cell)->value = (true);
	}

	return cell;
}
