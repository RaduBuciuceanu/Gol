#pragma once

#include <Cell.h>
#include <QAbstractItemModel>
#include <QVariant>

class CellModel : public QObject, public QVariant
{
	Q_OBJECT
	Q_PROPERTY(QString color READ color NOTIFY colorChanged)

private:
	const Cell* _cell;

public:
	explicit CellModel(QObject* parent = nullptr);

	explicit CellModel(const Cell* cell);

	QString color() const
	{
		if (_cell->value)
		{
			return "green";
		}

		return "red";
	}

signals:
	void colorChanged(QString color);
};
