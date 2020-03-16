// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "PCHeader.h"
#include "Player.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Player::Player(BalestraImageLoader* imageLoader, BalestraSoundLoader* soundLoader)
	{
		Player::imageLoader = imageLoader;
		Player::soundLoader = soundLoader;
	}

	Player::~Player()
	{
		unloadContent(currentWorld);
	}

	void Player::loadContent(BalestraWorld* world)
	{
		Balestra2DSprite::loadContent(world);

		setSizeMode(OBJ_SIZE_MODE_AUTO);
		setOriginMethod(OBJ_2D_ORIGIN_BOTTOM_CENTER);
		setPosition( BDoubleVector(400, 100) );

		// == ANIMATION SEQUENCE LOADING 
		// =============================================

		// -- IDLE -------------------------------------

		BImageInfo imageinfo;

		imageinfo.imagePath = "Images/claw_idle_1.png";
		pIdleSeq1 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_idle_2.png";
		pIdleSeq2 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_idle_3.png";
		pIdleSeq3 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_idle_4.png";
		pIdleSeq4 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_idle_5.png";
		pIdleSeq5 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_idle_6.png";
		pIdleSeq6 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_idle_7.png";
		pIdleSeq7 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_idle_8.png";
		pIdleSeq8 = imageLoader->loadImage(imageinfo);

		seqPlayerIdle = new BalestraAnimationSequence();

		seqPlayerIdle->addImage(pIdleSeq1);
		seqPlayerIdle->addImage(pIdleSeq2);
		seqPlayerIdle->addImage(pIdleSeq3);
		seqPlayerIdle->addImage(pIdleSeq4);
		seqPlayerIdle->addImage(pIdleSeq5);
		seqPlayerIdle->addImage(pIdleSeq6);
		seqPlayerIdle->addImage(pIdleSeq7);
		seqPlayerIdle->addImage(pIdleSeq8);

		seqPlayerIdle->setAnimtionUpdateRateMs(80);

		// -- RUNNING ----------------------------------

		imageinfo.imagePath = "Images/claw_run_1.png";
		pRunSeq1 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_2.png";
		pRunSeq2 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_3.png";
		pRunSeq3 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_4.png";
		pRunSeq4 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_5.png";
		pRunSeq5 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_6.png";
		pRunSeq6 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_7.png";
		pRunSeq7 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_8.png";
		pRunSeq8 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_9.png";
		pRunSeq9 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_run_10.png";
		pRunSeq10 = imageLoader->loadImage(imageinfo);

		seqPlayerRun = new BalestraAnimationSequence();

		seqPlayerRun->addImage(pRunSeq1);
		seqPlayerRun->addImage(pRunSeq2);
		seqPlayerRun->addImage(pRunSeq3);
		seqPlayerRun->addImage(pRunSeq4);
		seqPlayerRun->addImage(pRunSeq5);
		seqPlayerRun->addImage(pRunSeq6);
		seqPlayerRun->addImage(pRunSeq7);
		seqPlayerRun->addImage(pRunSeq8);
		seqPlayerRun->addImage(pRunSeq9);
		seqPlayerRun->addImage(pRunSeq10);

		seqPlayerRun->setAnimtionUpdateRateMs(100);

		// -- POUNCE -----------------------------------

		imageinfo.imagePath = "Images/claw_pounce.png";
		pPounceSeq1 = imageLoader->loadImage(imageinfo);

		seqPlayerPounce = new BalestraAnimationSequence();

		seqPlayerPounce->addImage(pPounceSeq1);

		// -- JUMP -------------------------------------

		imageinfo.imagePath = "Images/claw_jump_1.png";
		pJumpSeq1 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_jump_2.png";
		pJumpSeq2 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_jump_3.png";
		pJumpSeq3 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_jump_4.png";
		pJumpSeq4 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_jump_5.png";
		pJumpSeq5 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_jump_6.png";
		pJumpSeq6 = imageLoader->loadImage(imageinfo);

		imageinfo.imagePath = "Images/claw_jump_7.png";
		pJumpSeq7 = imageLoader->loadImage(imageinfo);

		seqPlayerJump = new BalestraAnimationSequence();

		seqPlayerJump->addImage(pJumpSeq1);
		seqPlayerJump->addImage(pJumpSeq2);
		seqPlayerJump->addImage(pJumpSeq3);
		seqPlayerJump->addImage(pJumpSeq4);
		seqPlayerJump->addImage(pJumpSeq5);
		seqPlayerJump->addImage(pJumpSeq6);
		seqPlayerJump->addImage(pJumpSeq7);

		seqPlayerJump->setAnimtionUpdateRateMs(50);
		seqPlayerJump->setOnSequenceEnd(ON_SEQUENCE_END_PAUSE);

		// == SOUND
		// =============================================

	}

	void Player::unloadContent(BalestraWorld* world)
	{
		Balestra2DSprite::unloadContent(world);

		// == RESOURCES

		if (seqPlayerIdle)
		{
			delete seqPlayerIdle;
		}

		if (seqPlayerRun)
		{
			delete seqPlayerRun;
		}

		if (seqPlayerPounce)
		{
			delete seqPlayerPounce;
		}

		if (seqPlayerJump)
		{
			delete seqPlayerJump;
		}
	}

	void Player::update(BalestraGameTime* gameTime)
	{
		Balestra2DSprite::update(gameTime);
	
		// == Y-Axis
		// =========================================

		// -- GRAVITY CALC -------------------------

		accelY = 8.f;

		if (playerStateY == PLAYER_STATEY_JUMPING)
		{
			if (calcJump == B_FALSE)
			{
				velY = -maxVelY / 2;
				posYBeforeJump = getPosition()->getY();
				calcJump = B_TRUE;
				canJump = B_FALSE;
			}

			accelY *= -1;
		}
		else if (calcJump == B_TRUE)
		{
			velY = maxVelY / 2;
		}

		velY += accelY;

		if (velY > maxVelY)
		{
			velY = maxVelY;
		}
		else if (velY < -maxVelY)
		{
			velY = -maxVelY;
		}

		float nextPosY = getPosition()->getY() + velY * gameTime->getDeltaTime();
		BRect nextRect = getRect(BDoubleVector(0, nextPosY));

		// -- COLLISION TREATMENT -------------------

		if (playerStateY == PLAYER_STATEY_FALLING)
		{
			if (nextRect.getHeight() >= playerMaxY)
			{
				velY = 0;
				playerStateY = PLAYER_STATEY_LANDED;
				nextPosY = playerMaxY;
				calcJump = B_FALSE;
				canJump = B_TRUE;
			}
		}
		else if (playerStateY == PLAYER_STATEY_JUMPING)
		{
			if (posYBeforeJump - nextPosY >= maxJump)
			{
				velY = maxVelY / 2;
				nextPosY = posYBeforeJump - maxJump;
				playerStateY = PLAYER_STATEY_FALLING;
			}
		}

		// -- APPLYING MOVIMENT --------------------

		getPosition()->setY(nextPosY);


		// == X-Axis
		// =========================================

		if (playerStateX == PLAYER_STATEX_IDLE)
		{
			accelX = 0.0f;
			velX = 0;
		}
		else
		{
			// -- MOVIMENTATION TRATMENT ---------------

			if (playerStateX == PLAYER_STATEX_RUN_L)
			{
				accelX = -50.f;
			}
			else if (playerStateX == PLAYER_STATEX_RUN_R)
			{
				accelX = 50.f;
			}

			velX += accelX;

			if (velX > maxVelX)
			{
				if (playerStateY == PLAYER_STATEY_JUMPING || playerStateY == PLAYER_STATEY_FALLING)
				{
					velX = maxVelX / 2;
				}
				else
				{
					velX = maxVelX;
				}
			}
			else if (velX < -maxVelX)
			{
				if (playerStateY == PLAYER_STATEY_JUMPING || playerStateY == PLAYER_STATEY_FALLING)
				{
					velX = -maxVelX / 2;
				}
				else
				{
					velX = -maxVelX;
				}
			}

			float nextPosX = 0;

			if (Player::isRunning == B_TRUE)
			{
				nextPosX = getPosition()->getX() + (velX * 1.6)  * (gameTime->getDeltaTime());
				seqPlayerRun->setAnimtionUpdateRateMs(60);
			}
			else
			{
				nextPosX = getPosition()->getX() + velX  * (gameTime->getDeltaTime());
				seqPlayerRun->setAnimtionUpdateRateMs(100);
			}

			BRect nextRect = getRect(  BDoubleVector(nextPosX, 0.f) );

			// -- COLLISION TRATMENT -------------------

			if (nextRect.getWidth() >= 1600)
			{
				nextPosX = 1600 - getOrigin()->getX() - 1;
			}

			if (nextRect.getX() <= 0)
			{
				nextPosX = getOrigin()->getX() + 1;
			}

			// -- APPLYING MOVIMENT --------------------

			getPosition()->setX(nextPosX);
			
		}

		/*
		std::string str = "VelY: ";
		str.append(std::to_string(velY * gameTime->deltaTime));
		str.append(". \n");
		OutputDebugStringA(str.c_str());*/

		// == DEFINING THE SEQUENCE 
		// =========================================

		if (playerStateY == PLAYER_STATEY_LANDED)
		{
			if (playerStateX == PLAYER_STATEX_IDLE)
			{
				accelX = 0.0f;
				velX = 0;
				getAnimationController()->setCurrentSequence(seqPlayerIdle);
			}
			else
			{
				if (playerStateX == PLAYER_STATEX_RUN_R)
				{
					getAnimationController()->setCurrentSequence(seqPlayerRun);
					setFlipX(false);
				}
				else if (playerStateX == PLAYER_STATEX_RUN_L)
				{
					getAnimationController()->setCurrentSequence(seqPlayerRun);
					setFlipX(true);
				}
			}
		}
		else if (playerStateY == PLAYER_STATEY_FALLING)
		{
			if (playerStateX == PLAYER_STATEX_IDLE)
			{
				accelX = 0.0f;
				velX = 0;
				
				if (getAnimationController()->getCurrentSequence() != seqPlayerJump)
				{
					getAnimationController()->setCurrentSequence(seqPlayerPounce);
				}
				else
				{
					if (getAnimationController()->getCurrentImage() == seqPlayerJump->getFrame(seqPlayerJump->getSizeOfSequence() - 1))
					{
						getAnimationController()->setCurrentSequence(seqPlayerPounce);
					}
				}
			}
			else
			{
				if (getAnimationController()->getCurrentSequence() == seqPlayerJump && getAnimationController()->getCurrentImage() == seqPlayerJump->getFrame(seqPlayerJump->getSizeOfSequence() - 1))
				{
					getAnimationController()->setCurrentSequence(seqPlayerPounce);
				}

				if (playerStateX == PLAYER_STATEX_RUN_R)
				{
					setFlipX(false);
				}
				else if (playerStateX == PLAYER_STATEX_RUN_L)
				{
					setFlipX(true);
				}
			}
		}
		else
		{

			if (playerStateX == PLAYER_STATEX_IDLE)
			{
				accelX = 0.0f;
				velX = 0;
				getAnimationController()->setCurrentSequence(seqPlayerJump);
			}
			else
			{
				if (playerStateX == PLAYER_STATEX_RUN_R)
				{
					getAnimationController()->setCurrentSequence(seqPlayerJump);
					setFlipX(false);
				}
				else if (playerStateX == PLAYER_STATEX_RUN_L)
				{
					getAnimationController()->setCurrentSequence(seqPlayerJump);
					setFlipX(true);
				}
			}
		}
	}

	void Player::draw(BalestraRenderGear* renderGear)
	{
		Balestra2DSprite::draw(renderGear);
	}

	void Player::idle()
	{
		setPlayerStateX(PLAYER_STATEX_IDLE);
	}

	void Player::onKeyLeftPress()
	{
		setPlayerStateX(PLAYER_STATEX_RUN_L);
		
	}

	void Player::onKeyRightPress()
	{
		setPlayerStateX(PLAYER_STATEX_RUN_R);
	}

	void Player::onSpaceBarPress()
	{
		if (canJump == B_TRUE)
		{
			playerStateY = PLAYER_STATEY_JUMPING;
		}
	}

	void Player::onSpaceBarNotPress()
	{
		playerStateY = PLAYER_STATEY_FALLING;
	}

	void Player::setPlayerStateX(float state)
	{
		if (state != Player::playerStateX)
		{
			velX = 0;
			Player::playerStateX = state;
		}
	}

	void Player::setPlayerStateY(float state)
	{
		if (state != Player::playerStateY)
		{
			velY = 0;
			Player::playerStateY = state;
		}
	}

	float Player::getVelX()
	{
		return Player::velX;
	}

	B_BOOL Player::getPlayerIsRunning()
	{
		return Player::isRunning;
	}

	void Player::setPlayerIsRunning(B_BOOL value)
	{
		Player::isRunning = value;
	}
}

