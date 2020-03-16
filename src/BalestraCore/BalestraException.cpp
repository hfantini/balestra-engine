// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraException.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraException::BalestraException(std::string message, std::string systemMessage, std::string solution)
	{
		if (message.size() != 0)
		{ 
			BalestraException::message = message;
		}

		if (systemMessage.size() != 0)
		{
			BalestraException::systemMessage = systemMessage;
		}

		if (solution.size() != 0)
		{
			BalestraException::solution = solution;
		}
	}

	std::string BalestraException::getMessage()
	{
		return message;
	}

	std::string BalestraException::getSystemMessage()
	{
		return systemMessage;
	}

	std::string BalestraException::getSolution()
	{
		return solution;
	}
}