#pragma once

#include "Preprocessor.h"

#include <IEvolveUniverse.h>
#include <IGalaxyRepository.h>

class ParallelEvolveUniverse
{
private:
	IGalaxyRepository* _galaxyRepository;

public:
	ParallelEvolveUniverse();

	~ParallelEvolveUniverse();

public:
	const Universe* execute(Input input) const;
};
