
// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraEnvironment.h"
#include "BalestraWorld.h"
#include "BalestraConfiguration.h"
#include "BalestraGameTime.h"
#include "BalestraMath.h"

namespace BalestraEngine
{
	// == GLOBAL DEFINITIONS
	// =====================================================

	// == IMPLEMENTATION: Methods
	// =====================================================

    BalestraEnvironment::~BalestraEnvironment()
	{
	}

	void BalestraEnvironment::initEnvironment()
	{
		BalestraMath::setRandomSeedValue(time(0));
	}

	void BalestraEnvironment::runEnvironment()
	{

	}

	void BalestraEnvironment::reloadEnvironment()
	{

	}

	void BalestraEnvironment::updateOptions()
	{

	}

	void BalestraEnvironment::destroyEnvironment()
	{
		if (gameTime)
		{
			gameTime->cleanDevice();
			delete gameTime;
		}
	}

	void BalestraEnvironment::exitGame()
	{

	}

	// == IMPLEMENTATION: Events
	// =====================================================

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BalestraWorld* BalestraEnvironment::getCurrentWorld()
	{
		return currentWorld;
	}

	BalestraConfiguration* BalestraEnvironment::getConfiguration()
	{
		return BalestraEnvironment::configuration;
	}

	unsigned long BalestraEnvironment::getCurrentSystemTimeInMillis()
	{
		return 0;
	}

	BalestraUserCommunication* BalestraEnvironment::getUserCommunicationInterface()
	{
		return BalestraEnvironment::userComm;
	}

	BalestraEnvironmentVideo* BalestraEnvironment::getVideoEnvironment()
	{
		return BalestraEnvironment::videoEnvironment;
	}

	BalestraEnvironmentSound* BalestraEnvironment::getSoundEnvironment()
	{
		return BalestraEnvironment::soundEnvironment;
	}

	BalestraEnvironmentInput* BalestraEnvironment::getInputEnvironment()
	{
		return BalestraEnvironment::inputEnvironment;
	}

	BalestraEnvironmentResource* BalestraEnvironment::getResourceEnvironment()
	{
		return BalestraEnvironment::resourceEnvironment;
	}

	void BalestraEnvironment::setCurrentWorld(BalestraWorld* world)
	{
		BalestraEnvironment::currentWorld = world;
		BalestraEnvironment::currentWorld->setEnvironment(this);
	}
}