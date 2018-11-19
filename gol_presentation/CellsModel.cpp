#include "CellsModel.h"

#include <CellRepository.h>
#include <QThread>

CellsModel::CellsModel()
{
	_cellRepository = new CellRepository();

	for (auto cell : _cellRepository->getAll())
	{
		auto model = new CellModel(cell);
		_cellModels.append(model);
	}
}

CellsModel::~CellsModel()
{
	delete _cellRepository;
}

int CellsModel::rowCount(const QModelIndex& parent) const
{
	return _cellModels.size();
}

QVariant CellsModel::data(const QModelIndex& index, int role) const
{
	CellModel* model = _cellModels.at(getIndex(index.row(), index.column()));
	return QVariant::fromValue(dynamic_cast<QObject*>(model));
}

int CellsModel::getIndex(int row, int column) const
{
	if (row == 0)
	{
		return (row + 1) * column;
	}
	else if (column == 0)
	{
		return (column + 1) * row;
	}

	return row * column;
}
