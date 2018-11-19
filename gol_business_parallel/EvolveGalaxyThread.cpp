#include "EvolveGalaxyThread.h"

#include <EvolveGalaxy.h>

EvolveGalaxyThread::EvolveGalaxyThread(const Galaxy* galaxy)
{
	_galaxy = galaxy;
}

void EvolveGalaxyThread::run()
{
	auto evolveGalaxy = EvolveGalaxy();
	evolveGalaxy.execute(_galaxy);
}
