// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION_GAMETIME

#define _INC_BEXCEPTION_GAMETIME

#include "BalestraException.h"

#endif

namespace BalestraEngine
{
	class BalestraGameTimeException : public BalestraException
	{
		public:
			BalestraGameTimeException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){}
		private:
		protected:
	};
}

