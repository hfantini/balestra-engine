// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraAnimationSequence.h"
#include "BalestraImage.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraAnimationSequence::BalestraAnimationSequence()
	{
		bImageVector = std::vector<BalestraImage*>();
	}

	BalestraAnimationSequence::BalestraAnimationSequence(BalestraImage* image)
	{
		bImageVector = std::vector<BalestraImage*>();

		addImage(image);
	}

	BalestraAnimationSequence::BalestraAnimationSequence(BalestraImage* imageArray[])
	{
		bImageVector = std::vector<BalestraImage*>();
	}

	BalestraAnimationSequence::~BalestraAnimationSequence()
	{
		for (int count = 0; count < bImageVector.size(); count++)
		{
			BalestraImage* image = bImageVector.at(count);

			if (image)
			{
				delete image;
			}
		}	
	}

	void BalestraAnimationSequence::addImage(BalestraImage* image)
	{
		bImageVector.push_back(image);
	}

	void BalestraAnimationSequence::removeImage(int frame)
	{

	}

	void BalestraAnimationSequence::removeImage(BalestraImage* image)
	{

	}

	BalestraImage* BalestraAnimationSequence::getFrame(int frame)
	{
		return bImageVector.at(frame);
	}

	int BalestraAnimationSequence::getSizeOfSequence()
	{
		return bImageVector.size();
	}

	int BalestraAnimationSequence::getAnimationUpdateRateMs()
	{
		return BalestraAnimationSequence::animationUpdateRateMs;
	}

	void BalestraAnimationSequence::setAnimtionUpdateRateMs(int rate)
	{
		BalestraAnimationSequence::animationUpdateRateMs = rate;
	}

	int BalestraAnimationSequence::getOnSequenceEnd()
	{
		return BalestraAnimationSequence::onSequenceEnd;
	}

	void BalestraAnimationSequence::setOnSequenceEnd(int onSequenceEnd)
	{
		BalestraAnimationSequence::onSequenceEnd = onSequenceEnd;
	}
}