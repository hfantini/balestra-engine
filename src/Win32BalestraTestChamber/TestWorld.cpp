// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// ===========================================================

#include "PCHeader.h"
#include "TestWorld.h"
#include "Scenario.h"
#include "Coin.h"
#include "Player.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	TestWorld::TestWorld()
	{
		TestWorld::setBackgroundColor( BalestraColorUtil::convertToFloatColor( B32ARGBColorUInt( 0, 0, 0, 255) ) );
	}

	TestWorld::~TestWorld()
	{

	}

	void TestWorld::loadContent()
	{
		BalestraWorld::loadContent();

		keyboard = getEnvironment()->getInputEnvironment()->getKeyboardDevice();

		// -- RESOURCE LOADING --------------
		w32Env = dynamic_cast<Win32BalestraEnvironment*>( getEnvironment() );
		mouse = getEnvironment()->getInputEnvironment()->getMouseDevice();
		
		imageLoader = getEnvironment()->getResourceEnvironment()->createImageLoader();
		soundLoader = getEnvironment()->getResourceEnvironment()->createSoundLoader();
		fontLoader = getEnvironment()->getResourceEnvironment()->createFontLoader();

		// --SCENARIO LOADING----------------

		BImageInfo imgInfo;
		imgInfo.imagePath = "Images/bg.jpg";
		bgImage = imageLoader->loadImage(imgInfo);

		seqBg = new BalestraAnimationSequence(bgImage);

		bg = new Balestra2DSprite();
		bg->loadContent(this);
		bg->setOriginMethod(OBJ_2D_ORIGIN_CENTER_CENTER);
		bg->getAnimationController()->setCurrentSequence(seqBg);
		bg->setPosition( BDoubleVector(0, -200) );

		scenario = new Scenario();
		scenario->loadContent(this, imageLoader);

		player = new Player(imageLoader, soundLoader);
		player->loadContent(this);

		coin = new Coin(imageLoader);
		coin->loadContent(this);

		//TEXT 
		BFontInfo fontInfo;
		fontInfo.fontPath = "D:\\Documentos\\Projetos\\Codecraft\\BalestraEngine\\Source\\Win32BalestraTestChamber\\Fonts\\times.ttf";

		font_times_16 = fontLoader->loadFont(fontInfo);

		creatorText = new Balestra2DText(font_times_16, "Created by: Henrique.F | Sprites by: Monolith");
		creatorText->setColor(BalestraColorUtil::convertToFloatColor(B32ARGBColorUInt(255, 255, 255, 255)));
		creatorText->setPosition(BDoubleVector(0, 0));

		dbgInfo = new BalestraDebugText();
		dbgInfo->loadContent(this);
		
	}

	void TestWorld::unloadContent()
	{
		// -- RESOURCE UNLOADING --------------

		if (seqBg)
		{
			delete seqBg;
		}

		// -- OBJECT UNLOADING ----------------

		if (bg)
		{
			delete bg;
		}

		if (scenario)
		{
			scenario->unloadCotent();
			delete scenario;
		}

		if (player)
		{
			delete player;
		}

		if (coin)
		{
			delete coin;
		}

		if (creatorText)
		{
			delete creatorText;
		}
		if (dbgInfo)
		{
			delete dbgInfo;
		}

		if (imageLoader)
		{
			delete imageLoader;
		}

		if (soundLoader)
		{
			delete soundLoader;
		}

		if (font_times_16)
		{
			font_times_16->unloadResource();
			delete font_times_16;
		}

		BalestraWorld::unloadContent();
	}

	void TestWorld::update(BalestraGameTime* gameTime)
	{
		BalestraWorld::update(gameTime);

		bg->update(gameTime);
		coin->update(gameTime);

		// HANDLING KEYBOARD INPUT

		//ACTIONS
		if (keyboard->getKeyState(BKEY_SHIFT) == BKEYBOARD_KEY_DOWN)
		{
			player->setPlayerIsRunning(B_TRUE);
		}
		else
		{
			player->setPlayerIsRunning(B_FALSE);
		}


		//MOVIMENTATION

		if ((keyboard->getKeyState(BKEY_LEFT) == BKEYBOARD_KEY_DOWN && keyboard->getKeyState(BKEY_RIGHT) == BKEYBOARD_KEY_DOWN) || (keyboard->getKeyState(BKEY_LEFT) == BKEYBOARD_KEY_UP && keyboard->getKeyState(BKEY_RIGHT) == BKEYBOARD_KEY_UP) )
		{
			player->idle();
		}
		else
		{
			if (keyboard->getKeyState(BKEY_LEFT) == BKEYBOARD_KEY_DOWN)
			{
				player->onKeyLeftPress();
			}
			else if (keyboard->getKeyState(BKEY_RIGHT) == BKEYBOARD_KEY_DOWN)
			{
				player->onKeyRightPress();
			}

		}

		if (keyboard->getKeyState(BKEY_SPACE_BAR) == BKEYBOARD_KEY_DOWN)
		{
			player->onSpaceBarPress();
		}
		else
		{
			player->onSpaceBarNotPress();
		}


		// UPDATING PLAYER

		player->update(gameTime);

		// CALCULING VIEWPORT

		BalestraCamera* camera = getEnvironment()->getVideoEnvironment()->getCamera();

		// -- X

		float vpX = player->getPosition()->getX() - 400;

		if (vpX < 0)
		{
			camera->setX(0);
		}
		else if (vpX > 800)
		{
			camera->setX(800);
		}
		else
		{
			bg->getPosition()->setX(vpX / 1.5f);
			camera->setX(vpX);
		}

		// -- Y

		float vpY = player->getPosition()->getY() - 600;

		if (vpY < 0)
		{
			camera->setY(0);
		}
		else if (vpY > 600)
		{
			camera->setY(600);
		}
		else
		{
			camera->setY(vpY);
		}

		creatorText->update(gameTime);
		//dbgInfo->update(gameTime);
	}

	void TestWorld::draw()
	{
		BalestraWorld::draw();

		renderGear->clearRenderTarget(getBackgroundColor());

		renderGear->startDraw();

		bg->draw(renderGear);

		coin->draw(renderGear);

		scenario->draw(renderGear);
		player->draw(renderGear);
		
		creatorText->draw(renderGear);
		//dbgInfo->draw(renderGear);

		renderGear->stopDraw();
	}
}