// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BEXCEPTION_PLATFORM

#define _INC_W32_BEXCEPTION_PLATFORM

#include "BalestraException.h"

#endif

namespace BalestraEngine
{
	class Win32BalestraPlatformException : public BalestraException
	{
		public:
			Win32BalestraPlatformException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){}
		private:
		protected:
	};
}
