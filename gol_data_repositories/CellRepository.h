#pragma once

#include "Preprocessor.h"

#include <Cell.h>
#include <Galaxy.h>
#include <ICellRepository.h>
#include <QList>

class GOL_DATA_REPOSITORIES_API CellRepository : public ICellRepository
{
private:
	static QList<const Cell*> _cells;

public:
	virtual ~CellRepository() override;

	const Cell* insert(const Cell* cell) override;

	QList<const Cell*> getAll() const override;

	QList<const Cell*> getChilds(const Galaxy* galaxy) const override;

	QList<const Cell*> getAliveNeighbors(const Cell* cell) const override;

	QList<const Cell*> getDeadNeighbors(const Cell* cell) const override;

private:
	bool isCellInGalaxy(const Cell* cell, const Galaxy* galaxy) const;

	bool isNeighbor(const Cell* foundCell, const Cell* cell) const;

	bool isHorizontalNeighbor(const Cell* foundCell, const Cell* cell) const;

	bool isVerticalNeighbor(const Cell* foundCell, const Cell* cell) const;

	bool isUpperLeftNeighbor(const Cell* foundCell, const Cell* cell) const;

	bool isUpperRightNeighbor(const Cell* foundCell, const Cell* cell) const;

	bool isLowerLeftNeighbor(const Cell* foundCell, const Cell* cell) const;

	bool isLowerRightNeighbor(const Cell* foundCell, const Cell* cell) const;
};
