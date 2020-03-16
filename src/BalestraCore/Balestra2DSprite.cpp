// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DSprite.h"
#include "BalestraRenderGear.h"
#include "BalestraImage.h"
#include "BalestraAnimationController.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Balestra2DSprite::Balestra2DSprite()
	{
		animationController = new BalestraAnimationController();
	}

	Balestra2DSprite::~Balestra2DSprite()
	{
		unloadContent(currentWorld);

		if (animationController)
		{
			delete animationController;
		}
	}

	void Balestra2DSprite::loadContent(BalestraWorld* world)
	{
		Balestra2DWorldObject::loadContent(world);

		// -- CALCULATING THE SIZE ----------
		if (getSizeMode() == OBJ_SIZE_MODE_AUTO && getAnimationController()->getCurrentImage())
		{
			size = getAnimationController()->getCurrentImage()->getSize();
		}

		Balestra2DWorldObject::updateOriginPoint();
	}

	void Balestra2DSprite::unloadContent(BalestraWorld* world)
	{
		Balestra2DWorldObject::unloadContent(world);
	}

	void Balestra2DSprite::update(BalestraGameTime* gameTime)
	{
		// -- ANIMATION UPDATE --------------==
		animationController->update(gameTime);

		// -- RECALCULATING THE SIZE ----------
		if (getSizeMode() == OBJ_SIZE_MODE_AUTO && getAnimationController()->getCurrentImage())
		{
			size = getAnimationController()->getCurrentImage()->getSize();
		}

		Balestra2DWorldObject::updateOriginPoint();

		Balestra2DWorldObject::update(gameTime);
	}

	void Balestra2DSprite::draw(BalestraRenderGear* renderGear)
	{
		Balestra2DWorldObject::draw(renderGear);

		renderGear->draw2DSprite(this);
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	int Balestra2DSprite::getSizeMode()
	{
		return Balestra2DSprite::sizeMode;
	}

	void Balestra2DSprite::setSizeMode(int sizeMode)
	{
		Balestra2DSprite::sizeMode = sizeMode;
	}

	BalestraAnimationController* Balestra2DSprite::getAnimationController()
	{
		return animationController;
	}
}
