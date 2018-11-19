#pragma once

#include "Preprocessor.h"

#include <Cell.h>
#include <Galaxy.h>
#include <QList>

class ICellRepository
{
public:
	virtual ~ICellRepository() = default;

	virtual const Cell* insert(const Cell* cell) = 0;

	virtual QList<const Cell*> getAll() const = 0;

	virtual QList<const Cell*> getChilds(const Galaxy* galaxy) const = 0;

	virtual QList<const Cell*> getAliveNeighbors(const Cell* cell) const = 0;

	virtual QList<const Cell*> getDeadNeighbors(const Cell* cell) const = 0;
};
