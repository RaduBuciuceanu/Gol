#pragma once

#include "Preprocessor.h"

#include <IEvolveGalaxy.h>
#include <IEvolveUniverse.h>
#include <IGalaxyRepository.h>
#include <IUniverseRepository.h>

class GOL_BUSINESS_SEQUENTIAL_API EvolveUniverse : public IEvolveUniverse
{
private:
	IUniverseRepository* _universeRepository;
	IGalaxyRepository* _galaxyRepository;
	IEvolveGalaxy* _evolveGalaxy;

public:
	explicit EvolveUniverse();

	virtual ~EvolveUniverse() override;

	const Universe* execute(Input input) override;
};
