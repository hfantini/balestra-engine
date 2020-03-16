// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION_VIDEO

#define _INC_BEXCEPTION_VIDEO

#include "BalestraException.h"

#endif

namespace BalestraEngine
{
	class BalestraVideoException : public BalestraException
	{
		public:
			BalestraVideoException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){}
		private:
		protected:
	};
}

