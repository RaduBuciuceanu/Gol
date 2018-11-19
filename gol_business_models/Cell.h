#pragma once

#include "Coordinates.h"
#include "Preprocessor.h"

#include <QObject>

class Cell : public QObject
{
public:
	Coordinates coordinate;
	bool value;
};
