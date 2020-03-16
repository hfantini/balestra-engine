// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraConfigurationDecoder.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	int BalestraConfigurationDecoder::getImageDecoderInterface()
	{
		return BalestraConfigurationDecoder::imageDecoderInterface;
	}

	void BalestraConfigurationDecoder::setImageDecoderInterface(int decoderInterface)
	{
		BalestraConfigurationDecoder::imageDecoderInterface = decoderInterface;
	}
}