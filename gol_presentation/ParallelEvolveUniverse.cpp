#include "ParallelEvolveUniverse.h"

#include <EvolveGalaxyThread.h>
#include <GalaxyRepository.h>
#include <QList>

ParallelEvolveUniverse::ParallelEvolveUniverse()
{
	_galaxyRepository = new GalaxyRepository();
}

ParallelEvolveUniverse::~ParallelEvolveUniverse()
{
	delete _galaxyRepository;
}

const Universe* ParallelEvolveUniverse::execute(Input input) const
{
	QList<EvolveGalaxyThread*> threads;

	for (const Galaxy* galaxy : _galaxyRepository->getAll())
	{
		auto thread = new EvolveGalaxyThread(galaxy);
		thread->start();
		threads.append(thread);
	}

	for (EvolveGalaxyThread* thread : threads)
	{
		thread->wait();
	}

	return nullptr;
}
