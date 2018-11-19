#pragma once

#include "Preprocessor.h"

#include <IGalaxyRepository.h>
#include <QList>

class GOL_DATA_REPOSITORIES_API GalaxyRepository : public IGalaxyRepository
{
private:
	static QList<const Galaxy*> _galaxies;

public:
	const Galaxy* insert(const Galaxy* galaxy);

	QList<const Galaxy*> getAll() const;
};
