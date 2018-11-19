#pragma once

#include "Preprocessor.h"

#include <Galaxy.h>
#include <QThread>

class GOL_BUSINESS_PARALLEL_API EvolveGalaxyThread : public QThread
{
private:
	const Galaxy* _galaxy;

public:
	explicit EvolveGalaxyThread(const Galaxy* galaxy);

protected:
	void run() override;
};
