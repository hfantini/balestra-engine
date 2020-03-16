// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION_INPUT

#define _INC_BEXCEPTION_INPUT

#include "BalestraException.h"

#endif

namespace BalestraEngine
{
	class BalestraInputException : public BalestraException
	{
		public:
			BalestraInputException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){}
		private:
		protected:
	};
}

