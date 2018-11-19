#pragma once

#include "Preprocessor.h"

#include <Galaxy.h>
#include <QList>

class IGalaxyRepository
{
public:
	virtual ~IGalaxyRepository() = default;

	virtual const Galaxy* insert(const Galaxy* galaxy) = 0;

	virtual QList<const Galaxy*> getAll() const = 0;
};
