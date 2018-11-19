#include "CellModel.h"

CellModel::CellModel(QObject* parent) : QObject(parent)
{
}

CellModel::CellModel(const Cell* cell) : QObject(nullptr)
{
	_cell = cell;
}
