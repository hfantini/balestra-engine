// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION_ANIMATION

#define _INC_BEXCEPTION_ANIMATION

#include "BalestraException.h"

#endif

namespace BalestraEngine
{
	class BalestraAnimationException : public BalestraException
	{
	public:
		BalestraAnimationException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){}
	private:
	protected:
	};
}