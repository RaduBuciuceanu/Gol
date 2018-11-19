#pragma once

#include "Preprocessor.h"

#include <IUniverseRepository.h>
#include <QList>

class GOL_DATA_REPOSITORIES_API UniverseRepository : public IUniverseRepository
{
private:
	static Universe* _universe;

public:
	const Universe* insert(const Universe* universe);

	const Universe* get() const;
};
