// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraDoubleVector.h"
#include "BalestraImage.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraImage::BalestraImage()
	{

	}

	BalestraImage::~BalestraImage()
	{
		unloadResource();
	}

	void BalestraImage::unloadResource()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BDoubleVector BalestraImage::getSize()
	{
		return BalestraImage::size;
	}

	void BalestraImage::setSize(BDoubleVector doubleVector)
	{
		BalestraImage::size = doubleVector;
	}

	std::string BalestraImage::getPath()
	{
		return BalestraImage::path;
	}

	void BalestraImage::setPath(std::string path)
	{
		BalestraImage::path = path;
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================
}