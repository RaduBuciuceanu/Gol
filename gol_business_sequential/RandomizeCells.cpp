#include "RandomizeCells.h"

#include <CellRepository.h>
#include <QRandomGenerator>

RandomizeCells::RandomizeCells()
{
	_cellRepository = new CellRepository();
}

RandomizeCells::~RandomizeCells()
{
	delete _cellRepository;
}

Output RandomizeCells::execute(Input input)
{
	auto generator = QRandomGenerator();

	for (const Cell* cell : _cellRepository->getAll())
	{
		bool isAlive = generator.generate() % 2 == 1;
		const_cast<Cell*>(cell)->value = isAlive;
	}

	return Output::nothing();
}
