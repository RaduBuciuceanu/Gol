#pragma once

#include <CellModel.h>
#include <ICellRepository.h>
#include <QAbstractListModel>
#include <QList>

class CellsModel : public QAbstractListModel
{
	Q_OBJECT

private:
	ICellRepository* _cellRepository;
	QList<CellModel*> _cellModels;

public:
	CellsModel();
	~CellsModel() override;

	int rowCount(const QModelIndex& parent) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
	int getIndex(int row, int column) const;
};
