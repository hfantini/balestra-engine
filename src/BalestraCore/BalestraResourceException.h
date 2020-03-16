// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION_RESOURCE

#define _INC_BEXCEPTION_RESOURCE

#include "BalestraException.h"

#endif

namespace BalestraEngine
{
	class BalestraResourceException : public BalestraException
	{
		public:
			BalestraResourceException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){}
		private:
		protected:
	};
}