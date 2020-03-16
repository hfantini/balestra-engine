// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraGameTime.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraEnvironment.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraGameTime::Win32BalestraGameTime(BalestraConfiguration* config) : BalestraGameTime(config)
	{

	}

	Win32BalestraGameTime::~Win32BalestraGameTime()
	{

	}

	void Win32BalestraGameTime::initDevice()
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
		secPerCount = 1.0f / countsPerSec;

		prevTime = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&prevTime);
	}

	void Win32BalestraGameTime::tickTime(BalestraWorld* world)
	{
			// == GETTING DELTA TIME =========================
		
			__int64 curTime = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&curTime);

			deltaTime = (curTime - prevTime) * secPerCount;

			// == CALCULATING TOTAL ELAPSED TIME =======

			totalElapsedTimeMS += deltaTime * 1000;
		
			// == CALCULATING CURRENT FPS (Frames/Sec) =

			frameCount++;
			elapsedTimeMSCount += deltaTime;

			if (elapsedTimeMSCount > 1.0f)
			{
				currentFPS = frameCount;

				frameCount = 0;
				elapsedTimeMSCount = 0;
			}

			// == UPDATE AND DRAW ======================
			if (configuration->getGameTimeConfiguration()->getRunning() == B_TRUE)
			{
				world->getEnvironment()->updateOptions();
				world->update(this);
				world->draw();
			}

			// == DEFINING THE PREVIOUS TIME ===========

			prevTime = curTime;
	}

	void Win32BalestraGameTime::cleanDevice()
	{

	}

	float Win32BalestraGameTime::syncWithTime(float value)
	{
		return value * deltaTime;
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

}