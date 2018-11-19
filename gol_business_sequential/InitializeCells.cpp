#include "InitializeCells.h"

#include <CellRepository.h>
#include <UniverseRepository.h>

InitializeCells::InitializeCells()
{
	_cellRepository = new CellRepository();
	_universeRepository = new UniverseRepository();
}

InitializeCells::~InitializeCells()
{
	delete _cellRepository;
	delete _universeRepository;
}

Output InitializeCells::execute(Input input)
{
	const Universe* universe = _universeRepository->get();

	for (int rowIndex = 0; rowIndex < universe->length; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < universe->width; columnIndex++)
		{
			auto coordinates = Coordinates{rowIndex, columnIndex};
			auto cell = new Cell();
			cell->coordinate = coordinates;
			cell->value = false;
			_cellRepository->insert(cell);
		}
	}

	return Output::nothing();
}
