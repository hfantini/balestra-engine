// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraGameTime.h"
#include "BalestraConstants.h"
#include "BalestraEnvironment.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraGameTime::BalestraGameTime(BalestraConfiguration* config)
	{
		BalestraGameTime::configuration = config;
	}

	BalestraGameTime::~BalestraGameTime()
	{

	}

	void BalestraGameTime::initDevice()
	{

	}

	void BalestraGameTime::tickTime(BalestraWorld* world)
	{

	}

	void BalestraGameTime::cleanDevice()
	{

	}

	float BalestraGameTime::syncWithTime(float value)
	{
		return value;
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	int BalestraGameTime::getCurrentFPS()
	{
		return BalestraGameTime::currentFPS;
	}

	long BalestraGameTime::getTotalElapsedTimeInMS()
	{
		return (long) totalElapsedTimeMS;
	}

	long BalestraGameTime::getTotalElapsedTimeInSec()
	{
		return  (long) (totalElapsedTimeMS / 1000);
	}

	float BalestraGameTime::getDeltaTime()
	{
		return BalestraGameTime::deltaTime;
	}

	std::string BalestraGameTime::getGameTimeInfo()
	{
		std::string message = "GameTime Info: { FPS: ";
		message.append(std::to_string(currentFPS));
		message.append(" | ");		

		message.append("Elapsed Time (Sec/Ms): ");
		message.append(std::to_string(getTotalElapsedTimeInSec()));
		message.append(" Sec. / ");
		message.append(std::to_string(getTotalElapsedTimeInMS()));
		message.append(" Ms. | ");

		message.append(" Delta Time: ");
		message.append(std::to_string(getDeltaTime()));
		message.append(" } \n");
		
		/*

		message.append("Last Sleep: ");
		message.append(std::to_string(sleepTime));
		message.append(" ms. | ");

		message.append("Last Update&Draw: ");
		message.append(std::to_string(updateAndDrawElapsedTimeOnLastUpdate));
		message.append(" ms. } "); */

		return message;
	}
}