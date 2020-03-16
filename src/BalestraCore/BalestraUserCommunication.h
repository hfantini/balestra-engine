// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BUSER_COMM

#define _INC_BUSER_COMM

#include "BalestraPrecompiledHeader.h"
#include "BalestraException.h"

namespace BalestraEngine
{
	class BalestraUserCommunication
	{
		public:
			~BalestraUserCommunication();
			virtual void consoleWarningMessage(std::string message);
			virtual void consoleErrorMessage(std::string message);
			virtual void consoleInfoMessage(std::string message);
			virtual void consoleExceptionMessage(BalestraException* ex);
			virtual void platformWarningMessage(std::string title, std::string message);
			virtual void platformErrorMessage(std::string title, std::string message);
			virtual void platformInfoMessage(std::string title, std::string message);
			virtual void platformExceptionMessage(BalestraException* ex);
		private:
		protected:
	};
}

#endif