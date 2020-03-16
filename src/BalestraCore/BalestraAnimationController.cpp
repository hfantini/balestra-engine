// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraAnimationController.h"
#include "BalestraImage.h"
#include "BalestraAnimationSequence.h"
#include "BalestraGameTime.h"
#include "BalestraAnimationException.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraAnimationController::BalestraAnimationController()
	{

	}

	BalestraAnimationController::~BalestraAnimationController()
	{

	}

	void BalestraAnimationController::update(BalestraGameTime* gameTime)
	{
		if (currentSequence)
		{
			animationUpdateRateCounter += gameTime->syncWithTime(1000);

			if (animationUpdateRateCounter > currentSequence->getAnimationUpdateRateMs())
			{
				animationUpdateRateCounter = 0;

				switch (animationState)
				{
					case ANIMATION_PLAY_STATE:

						switch (animationPlaySense)
						{
							case ANIMATION_PLAY_SENSE_NORMAL:

							currentFrame++;

							if (currentFrame >= currentSequence->getSizeOfSequence())
							{
								switch (currentSequence->getOnSequenceEnd())
								{
								case ON_SEQUENCE_END_REPEAT:
									currentFrame = 0;
									break;

								case ON_SEQUENCE_END_PAUSE:
									currentFrame = currentSequence->getSizeOfSequence() - 1;
									setAnimationState(ANIMATION_PAUSE_STATE);
									break;

								case ON_SQUENCE_END_STOP:
									setAnimationState(ANIMATION_STOP_STATE);
									break;

								default:
									throw new BalestraAnimationException("Error at end of animation sequence", "Can't define the valid option to OnSequenceEnd value", "");
									break;
								}
							}

							break;

							case ANIMATION_PLAY_SENSE_REVERSE:
								break;

							default:
								throw new BalestraAnimationException("Error at update an animation sequence", "Can't define the valid option to AnimationState value", "");
								break;
						}

						break;

					case ANIMATION_STOP_STATE:
						setCurrentFrame(0);
						break;

					case ANIMATION_PAUSE_STATE:

						break;

					default:
						throw new BalestraAnimationException("Error at update an animation sequence", "Can't define the valid option to OnSequenceEnd value", "");
						break;
				}
			}
		}
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	int BalestraAnimationController::getAnimationState()
	{
		return BalestraAnimationController::animationState;
	}

	void BalestraAnimationController::setAnimationState(int state)
	{
		BalestraAnimationController::animationState = state;
	}

	int BalestraAnimationController::getAnimationPlaySense()
	{
		return BalestraAnimationController::animationPlaySense;
	}

	void BalestraAnimationController::setAnimationPlaySense(int playSense)
	{
		BalestraAnimationController::animationPlaySense = playSense;
	}

	int BalestraAnimationController::getCurrentFrame()
	{
		return BalestraAnimationController::currentFrame;
	}

	void BalestraAnimationController::setCurrentFrame(int currentFrame)
	{
		BalestraAnimationController::currentFrame = currentFrame;
	}

	BalestraImage* BalestraAnimationController::getCurrentImage()
	{
		if (currentSequence)
		{
			return getCurrentSequence()->getFrame(getCurrentFrame());
		}

		return{ 0 };
	}

	BalestraAnimationSequence* BalestraAnimationController::getCurrentSequence()
	{
		return BalestraAnimationController::currentSequence;
	}

	void BalestraAnimationController::setCurrentSequence(BalestraAnimationSequence* sequence)
	{
		if (BalestraAnimationController::currentSequence != sequence)
		{
			currentFrame = 0;
			setAnimationState(ANIMATION_PLAY_STATE);
		}

		BalestraAnimationController::currentSequence = sequence;
	}
}