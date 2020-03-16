// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION_SOUND

#define _INC_BEXCEPTION_SOUND

#include "BalestraException.h"

#endif

namespace BalestraEngine
{
	class BalestraSoundException : public BalestraException
	{
	public:
		BalestraSoundException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){}
	private:
	protected:
	};
}

