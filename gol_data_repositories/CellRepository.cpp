#include "CellRepository.h"

#include <QtMath>

QList<const Cell*> CellRepository::_cells = QList<const Cell*>();

CellRepository::~CellRepository() = default;

const Cell* CellRepository::insert(const Cell* cell)
{
	_cells.append(cell);
	return cell;
}

QList<const Cell*> CellRepository::getAll() const
{
	return _cells;
}

QList<const Cell*> CellRepository::getChilds(const Galaxy* galaxy) const
{
	QList<const Cell*> result;

	for (const Cell* cell : _cells)
	{
		if (isCellInGalaxy(cell, galaxy))
		{
			result.append(cell);
		}
	}

	return result;
}

QList<const Cell*> CellRepository::getAliveNeighbors(const Cell* cell) const
{
	QList<const Cell*> result;

	for (const Cell* foundCell : _cells)
	{
		if (foundCell->value && isNeighbor(foundCell, cell))
		{
			result.append(cell);
		}
	}

	return result;
}

QList<const Cell*> CellRepository::getDeadNeighbors(const Cell* cell) const
{
	QList<const Cell*> result;

	for (const Cell* foundCell : _cells)
	{
		if (!foundCell->value && isNeighbor(foundCell, cell))
		{
			result.append(cell);
		}
	}

	return result;
}

bool CellRepository::isCellInGalaxy(const Cell* cell, const Galaxy* galaxy) const
{
	bool one = cell->coordinate.x >= (galaxy->index + 1) * galaxy->width;
	bool two = cell->coordinate.x <= (galaxy->index + 1) * galaxy->width + galaxy->width;

	return one && two;
}

bool CellRepository::isNeighbor(const Cell* foundCell, const Cell* cell) const
{
	return isHorizontalNeighbor(foundCell, cell) || isVerticalNeighbor(foundCell, cell) ||
		   isUpperLeftNeighbor(foundCell, cell) || isUpperRightNeighbor(foundCell, cell) ||
		   isLowerLeftNeighbor(foundCell, cell) || isLowerRightNeighbor(foundCell, cell);
}

bool CellRepository::isHorizontalNeighbor(const Cell* foundCell, const Cell* cell) const
{
	return qAbs(foundCell->coordinate.x - cell->coordinate.x) == 1;
}

bool CellRepository::isVerticalNeighbor(const Cell* foundCell, const Cell* cell) const
{
	return qAbs(foundCell->coordinate.y - cell->coordinate.y) == 1;
}

bool CellRepository::isUpperLeftNeighbor(const Cell* foundCell, const Cell* cell) const
{
	bool xMatch = foundCell->coordinate.x == cell->coordinate.x - 1;
	bool yMatch = foundCell->coordinate.y == cell->coordinate.y + 1;
	return xMatch && yMatch;
}

bool CellRepository::isUpperRightNeighbor(const Cell* foundCell, const Cell* cell) const
{
	bool xMatch = foundCell->coordinate.x == cell->coordinate.x + 1;
	bool yMatch = foundCell->coordinate.y == cell->coordinate.y + 1;
	return xMatch && yMatch;
}

bool CellRepository::isLowerLeftNeighbor(const Cell* foundCell, const Cell* cell) const
{
	bool xMatch = foundCell->coordinate.x == cell->coordinate.x - 1;
	bool yMatch = foundCell->coordinate.y == cell->coordinate.y - 1;
	return xMatch && yMatch;
}

bool CellRepository::isLowerRightNeighbor(const Cell* foundCell, const Cell* cell) const
{
	bool xMatch = foundCell->coordinate.x == cell->coordinate.x + 1;
	bool yMatch = foundCell->coordinate.y == cell->coordinate.y - 1;
	return xMatch && yMatch;
}
