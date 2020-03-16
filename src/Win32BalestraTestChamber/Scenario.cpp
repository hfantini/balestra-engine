// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "PCHeader.h"
#include "Scenario.h"
#include "TestWorld.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Scenario::Scenario()
	{

	}

	Scenario::~Scenario()
	{

	}

	void Scenario::loadContent(BalestraWorld* world, BalestraImageLoader* loader)
	{
		//LOADING SEQUENCES
		BImageInfo imageinfo;

		imageinfo.imagePath = "Images/tile2.png";
		imgWalkSeq1 = loader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/tile1.png";
		imgBrickSeq1 = loader->loadImage(imageinfo);

		seqWalkPlatform = new BalestraAnimationSequence(imgWalkSeq1);
		seqBrick = new BalestraAnimationSequence(imgBrickSeq1);

		//CALCULING SCREEN WIDTH / TILE

		TestWorld* tWorld = dynamic_cast<TestWorld*>(world);
		marginY = tWorld->w32Env->getWin32Configuration()->getPlatformConfiguration()->getWindowRect()->getHeight() - (64 * tileY);

		for (int countY = 0; countY < tileY; countY++)
		{
			for (int countX = 0; countX < tileX; countX++)
			{
				if (countY == 0)
				{
					spriteArray[countX][countY] = new Balestra2DSprite();
					spriteArray[countX][countY]->getAnimationController()->setCurrentSequence(seqWalkPlatform);
				}
				else
				{
					spriteArray[countX][countY] = new Balestra2DSprite();
					spriteArray[countX][countY]->getAnimationController()->setCurrentSequence(seqBrick);
				}

				spriteArray[countX][countY]->setSize(BDoubleVector(64.f, 64.f));
				spriteArray[countX][countY]->setPosition(BDoubleVector(64.f * (float) countX, (64.f * (float) countY) + marginY ));
				spriteArray[countX][countY]->setSizeMode(OBJ_SIZE_MODE_CUSTOM);
				spriteArray[countX][countY]->setSizeMode(OBJ_2D_ORIGIN_UP_LEFT);
				spriteArray[countX][countY]->loadContent(tWorld);
			}
		}
	}

	void Scenario::unloadCotent()
	{
		for (int countY = 0; countY < tileY; countY++)
		{
			for (int countX = 0; countX < tileX; countX++)
			{
				delete spriteArray[countX][countY];
			}
		}

		if (seqWalkPlatform)
		{
			delete seqWalkPlatform;
		}

		if (seqBrick)
		{
			delete seqBrick;
		}

	}

	void Scenario::draw(BalestraRenderGear* renderGear)
	{
		for (int countY = 0; countY < tileY; countY++)
		{
			for (int countX = 0; countX < tileX; countX++)
			{
				spriteArray[countX][countY]->draw(renderGear);
			}
		}
	}
}

