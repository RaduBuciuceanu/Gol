#include <EvolveGalaxy.h>
#include <EvolveUniverse.h>
#include <GalaxyRepository.h>
#include <InitializeCells.h>
#include <InitializeGalaxies.h>
#include <InitializeUniverse.h>
#include <ParallelEvolveUniverse.h>
#include <QCoreApplication>
#include <QElapsedTimer>
#include <QLoggingCategory>
#include <QThread>
#include <QVariant>
#include <RandomizeCells.h>
#include <iostream>

void executeSequential(int universeSize, int galaxiesCount)
{
	std::cout << "Sequential algorythm was started." << std::endl;

	auto timer = QElapsedTimer();
	timer.start();

	std::cout << "Timer was started." << std::endl;

	auto initializeUniverse = new InitializeUniverse();
	initializeUniverse->execute(universeSize);

	std::cout << "Universe was initialized." << std::endl;

	auto initializeGalaxies = new InitializeGalaxies();
	initializeGalaxies->execute(galaxiesCount);

	std::cout << "Galaxies were initialized." << std::endl;

	auto initializeCells = new InitializeCells();
	initializeCells->execute(Input::nothing());

	std::cout << "Cells were initialized." << std::endl;

	auto randomizeCells = new RandomizeCells();
	randomizeCells->execute(Input::nothing());

	std::cout << "Cells were randomized." << std::endl;

	auto evolveUniverse = new EvolveUniverse();
	evolveUniverse->execute(Input::nothing());

	std::cout << "Universe evolution was done." << std::endl;

	std::cout << "Sequential algorithm was ended. Elapsed time: " << timer.elapsed() << std::endl;
}

void executeParallel(int universeSize, int galaxiesCount)
{
	std::cout << "Parallel algorythm was started." << std::endl;

	auto timer = QElapsedTimer();
	timer.start();

	std::cout << "Timer was started." << std::endl;

	auto initializeUniverse = new InitializeUniverse();
	initializeUniverse->execute(universeSize);

	std::cout << "Universe was initialized." << std::endl;

	auto initializeGalaxies = new InitializeGalaxies();
	initializeGalaxies->execute(galaxiesCount);

	std::cout << "Galaxies were initialized." << std::endl;

	auto initializeCells = new InitializeCells();
	initializeCells->execute(Input::nothing());

	std::cout << "Cells were initialized." << std::endl;

	auto randomizeCells = new RandomizeCells();
	randomizeCells->execute(Input::nothing());

	std::cout << "Cells were randomized." << std::endl;

	auto parallelEvolveUniverse = new ParallelEvolveUniverse();
	parallelEvolveUniverse->execute(Input::nothing());

	std::cout << "Universe evolution was done." << std::endl;

	std::cout << "Parallel algorithm was ended. Elapsed time: " << timer.elapsed() << std::endl;
}

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	std::cout << "Set the universe size: ";
	int universeSize;
	std::cin >> universeSize;

	std::cout << "Set the galaxies count: ";
	int galaxiesCount;
	std::cin >> galaxiesCount;

	std::cout << "Press 0 for sequential execution." << std::endl;
	std::cout << "Press 1 for parallel executeion." << std::endl;
	std::cout << "Your choice: ";
	int selectedType;
	std::cin >> selectedType;

	if (selectedType == 0)
	{
		executeSequential(universeSize, galaxiesCount);
	}
	else
	{
		executeParallel(universeSize, galaxiesCount);
	}

	return 0;
}
