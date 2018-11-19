#include "GolModel.h"

#include "CellModel.h"

#include <CellModel.h>
#include <CellRepository.h>
#include <EvolveGalaxy.h>
#include <GalaxyRepository.h>
#include <InitializeCells.h>
#include <InitializeGalaxies.h>
#include <InitializeUniverse.h>
#include <ParallelEvolveUniverse.h>
#include <QCoreApplication>
#include <QList>
#include <QThread>
#include <QVariant>
#include <QtConcurrent/QtConcurrent>
#include <RandomizeCells.h>

GolModel::GolModel()
{
	_initializeUniverse = new InitializeUniverse();
	_initializeGalaxies = new InitializeGalaxies();
	_initializeCells = new InitializeCells();
	_randomizeCells = new RandomizeCells();
	_evolveUniverse = new EvolveUniverse();
	_cellRepository = new CellRepository();
	_timer = new QElapsedTimer();
	_cells = new CellsModel();
	_isLoading = false;
}

GolModel::~GolModel()
{
	delete _initializeUniverse;
	delete _initializeGalaxies;
	delete _initializeCells;
	delete _randomizeCells;
	delete _cellRepository;
	delete _timer;
}

QString GolModel::elapsedTime() const
{
	return _elapsedTime;
}

bool GolModel::isLoading() const
{
	return _isLoading;
}

CellsModel* GolModel::cells() const
{
	return _cells;
}

QString GolModel::universeSize() const
{
	return _universeHeight;
}

QString GolModel::galaxiesCount() const
{
	return _galaxiesCount;
}

void GolModel::initializeUniverse()
{
	startTimer();
	_initializeUniverse->execute(_universeHeight.toInt());
	stopTimer();
}

void GolModel::initializeGalaxies()
{
	startTimer();
	_initializeGalaxies->execute(_galaxiesCount.toInt());
	stopTimer();
}

void GolModel::initializeCells()
{
	startTimer();
	_initializeCells->execute(Input::nothing());
	stopTimer();
}

void GolModel::randomizeCells()
{
	startTimer();
	_randomizeCells->execute(Input::nothing());
	stopTimer();
}

void GolModel::refreshCellsModels()
{
	delete _cells;

	_cells = new CellsModel();
	cellsChanged(_cells);
}

void GolModel::evolveSingleThread()
{
	startTimer();

	QThread* thread = QThread::create([this]() -> void { _evolveUniverse->execute(Input::nothing()); });
	connect(thread, SIGNAL(finished()), this, SLOT(stopTimer()), Qt::ConnectionType::QueuedConnection);

	thread->start();
}

void GolModel::evolveMultipleThreads()
{
	startTimer();

	QThread* thread = QThread::create([this]() -> void {
		auto parallelEvolveUniverse = new ParallelEvolveUniverse();
		parallelEvolveUniverse->execute(Input::nothing());
		delete parallelEvolveUniverse;
	});

	connect(thread, SIGNAL(finished()), this, SLOT(stopTimer()), Qt::ConnectionType::QueuedConnection);

	thread->start();
}

void GolModel::startTimer()
{
	setIsLoading(true);
	QCoreApplication::processEvents();
	_timer->start();
}

void GolModel::stopTimer()
{
	_elapsedTime = QString::number(_timer->elapsed());
	elapsedTimeChanged(_elapsedTime);
	setIsLoading(false);
	refreshCellsModels();
}

void GolModel::setUniverseSize(QString universeHeight)
{
	_universeHeight = universeHeight;
	emit universeSizeChanged(_universeHeight);
}

void GolModel::setGalaxiesCount(QString galaxiesCount)
{
	_galaxiesCount = galaxiesCount;
	emit galaxiesCountChanged(_galaxiesCount);
}

void GolModel::setIsLoading(bool value)
{
	_isLoading = value;
	isLoadingChanged(value);
}
