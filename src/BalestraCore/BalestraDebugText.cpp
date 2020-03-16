// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraDebugText.h"
#include "Balestra2DText.h"
#include "BalestraGameTime.h"
#include "BalestraColorUtil.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraDebugText::BalestraDebugText()
	{

	}

	BalestraDebugText::~BalestraDebugText()
	{
		unloadContent(debugMode->getCurrentWorld());
	}

	void BalestraDebugText::loadContent(BalestraWorld* world)
	{
		// -- DEBUG MODE ---------------------------
		debugMode = new Balestra2DText(NULL, "DEBUG MODE: ON");
		debugMode->setColor(BalestraColorUtil::convertToFloatColor(B32ARGBColorUInt(255, 255, 0, 0)));
		debugMode->setPosition(BDoubleVector(0, 0));

		// -- GAMETIME INFO ------------------------
		gameTimeDbgText = new Balestra2DText(NULL, "");
		gameTimeDbgText->setColor(BalestraColorUtil::convertToFloatColor(B32ARGBColorUInt(255, 255, 255, 255)));
		gameTimeDbgText->setPosition(BDoubleVector(0, 20));
	}

	void BalestraDebugText::unloadContent(BalestraWorld* world)
	{
		if (debugMode)
		{
			delete debugMode;
		}

		if (gameTimeDbgText)
		{
			delete gameTimeDbgText;
		}
	}

	void BalestraDebugText::update(BalestraGameTime* gameTime)
	{
		// -- DEBUG MODE ---------------------
		debugMode->update(gameTime);

		// -- GAMETIME INFO ------------------
		gameTimeDbgText->setText(gameTime->getGameTimeInfo());
		gameTimeDbgText->update(gameTime);
	}

	void BalestraDebugText::draw(BalestraRenderGear* renderGear)
	{
		debugMode->draw(renderGear);
		gameTimeDbgText->draw(renderGear);
	}


}