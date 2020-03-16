// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION_SYSTEM_INCOMPATIBILITY

#define _INC_BEXCEPTION_SYSTEM_INCOMPATIBILITY

#include "BalestraException.h"

#endif

namespace BalestraEngine
{
	class BalestraSystemIncompatibilityException : public BalestraException
	{
		public:
			BalestraSystemIncompatibilityException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){}
		private:
		protected:
	};
}