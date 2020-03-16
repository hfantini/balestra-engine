// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraConfigurationDebug.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraConfigurationDebug::BalestraConfigurationDebug()
	{

	}

	BalestraConfigurationDebug::~BalestraConfigurationDebug()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	B_BOOL BalestraConfigurationDebug::getDebugMode()
	{
		return BalestraConfigurationDebug::debugMode;
	}

	void BalestraConfigurationDebug::setDebugMode(B_BOOL value)
	{
		BalestraConfigurationDebug::debugMode = value;
	}



}