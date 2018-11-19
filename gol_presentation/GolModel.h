#pragma once

#include <CellModel.h>
#include <CellsModel.h>
#include <EvolveUniverse.h>
#include <InitializeCells.h>
#include <InitializeGalaxies.h>
#include <InitializeUniverse.h>
#include <QAbstractListModel>
#include <QElapsedTimer>
#include <QList>
#include <QObject>
#include <QQmlListProperty>
#include <QStandardItemModel>
#include <QVariant>
#include <RandomizeCells.h>

class GolModel : public QStandardItemModel
{
	Q_OBJECT
	Q_PROPERTY(QString elapsedTime READ elapsedTime NOTIFY elapsedTimeChanged)
	Q_PROPERTY(bool isLoading READ isLoading NOTIFY isLoadingChanged)
	Q_PROPERTY(CellsModel* cells READ cells NOTIFY cellsChanged)
	Q_PROPERTY(QString universeSize READ universeSize WRITE setUniverseSize NOTIFY universeSizeChanged)
	Q_PROPERTY(QString galaxiesCount READ galaxiesCount WRITE setGalaxiesCount NOTIFY galaxiesCountChanged)

private:
	IInitializeUniverse* _initializeUniverse;
	IInitializeGalaxies* _initializeGalaxies;
	IInitializeCells* _initializeCells;
	IRandomizeCells* _randomizeCells;
	IEvolveUniverse* _evolveUniverse;
	ICellRepository* _cellRepository;
	QElapsedTimer* _timer;
	QString _elapsedTime;
	bool _isLoading;
	CellsModel* _cells;
	QString _universeHeight;
	QString _universeWidth;
	QString _galaxiesCount;

public:
	explicit GolModel();

	~GolModel() override;

	QString elapsedTime() const;

	bool isLoading() const;

	CellsModel* cells() const;

	QString universeSize() const;

	QString galaxiesCount() const;

	Q_INVOKABLE void initializeUniverse();

	Q_INVOKABLE void initializeGalaxies();

	Q_INVOKABLE void initializeCells();

	Q_INVOKABLE void randomizeCells();

	Q_INVOKABLE void evolveSingleThread();

	Q_INVOKABLE void evolveMultipleThreads();

public slots:
	void stopTimer();

	void setUniverseSize(QString universeHeight);

	void setGalaxiesCount(QString galaxiesCount);

signals:
	void elapsedTimeChanged(QString elapsedTime);

	void isLoadingChanged(bool isLoading);

	void cellsChanged(CellsModel* cells);

	void universeSizeChanged(QString universeHeight);

	void galaxiesCountChanged(QString galaxiesCount);

private:
	void startTimer();
	void setIsLoading(bool value);
	void refreshCellsModels();
};
