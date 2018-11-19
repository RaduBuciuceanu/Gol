#pragma once

#include "Preprocessor.h"

#include <IGalaxyRepository.h>
#include <IInitializeGalaxies.h>
#include <IUniverseRepository.h>

class GOL_BUSINESS_SEQUENTIAL_API InitializeGalaxies : public IInitializeGalaxies
{
private:
	IGalaxyRepository* _galaxyRepository;
	IUniverseRepository* _universeRepository;

public:
	explicit InitializeGalaxies();

	virtual ~InitializeGalaxies() override;

	Output execute(int count) override;

private:
	int getGalaxyLength(int requiredCount, bool isLastOne) const;
};
