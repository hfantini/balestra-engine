// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "PCHeader.h"
#include "Coin.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Coin::Coin(BalestraImageLoader* imageLoader)
	{
		Coin::imageLoader = imageLoader;
	}

	Coin::~Coin()
	{
		if (seqCoin)
		{
			delete seqCoin;
		}
	}

	void Coin::loadContent(BalestraWorld* world)
	{
		Balestra2DSprite::loadContent(world);

		setOriginMethod(OBJ_2D_ORIGIN_CENTER_CENTER);
		setPosition(BDoubleVector(100, 100));

		seqCoin = new BalestraAnimationSequence();
		BImageInfo imageInfo;

		imageInfo.imagePath = "Images/coin1.png";
		mSeq1 = imageLoader->loadImage(imageInfo);

		imageInfo.imagePath = "Images/coin2.png";
		mSeq2 = imageLoader->loadImage(imageInfo);

		imageInfo.imagePath = "Images/coin3.png";
		mSeq3 = imageLoader->loadImage(imageInfo);

		imageInfo.imagePath = "Images/coin4.png";
		mSeq4 = imageLoader->loadImage(imageInfo);

		imageInfo.imagePath = "Images/coin5.png";
		mSeq5 = imageLoader->loadImage(imageInfo);

		imageInfo.imagePath = "Images/coin6.png";
		mSeq6 = imageLoader->loadImage(imageInfo);

		imageInfo.imagePath = "Images/coin7.png";
		mSeq7 = imageLoader->loadImage(imageInfo);

		seqCoin->addImage(mSeq1);
		seqCoin->addImage(mSeq2);
		seqCoin->addImage(mSeq3);
		seqCoin->addImage(mSeq4);
		seqCoin->addImage(mSeq5);
		seqCoin->addImage(mSeq6);
		seqCoin->addImage(mSeq7);

		seqCoin->setAnimtionUpdateRateMs(80);

		getAnimationController()->setCurrentSequence(seqCoin);
	}

	void Coin::unloadContent(BalestraWorld* world)
	{
		Balestra2DSprite::unloadContent(world);
	}

	void Coin::update(BalestraGameTime* gameTime)
	{
		Balestra2DSprite::update(gameTime);
	}

	void Coin::draw(BalestraRenderGear* renderGear)
	{
		Balestra2DSprite::draw(renderGear);
	}
}

