#pragma once

#include "Preprocessor.h"

#include <IInitializeUniverse.h>
#include <IUniverseRepository.h>
#include <Universe.h>
#include <UniverseRepository.h>

class GOL_BUSINESS_SEQUENTIAL_API InitializeUniverse : public IInitializeUniverse
{
private:
	IUniverseRepository* _universeRepository;

public:
	explicit InitializeUniverse();

	virtual ~InitializeUniverse() override;

	const Universe* execute(int input) override;
};
