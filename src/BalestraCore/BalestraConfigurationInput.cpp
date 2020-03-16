// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraConfigurationInput.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	int BalestraConfigurationInput::getInputInterface()
	{
		return BalestraConfigurationInput::inputInterface;
	}

	void BalestraConfigurationInput::setInputInterface(int interfaceValue)
	{
		BalestraConfigurationInput::inputInterface = interfaceValue;
	}

	int BalestraConfigurationInput::getInputType()
	{
		return BalestraConfigurationInput::inputType;
	}

	void BalestraConfigurationInput::setInputType(int inputType)
	{
		BalestraConfigurationInput::inputType = inputType;
	}
}