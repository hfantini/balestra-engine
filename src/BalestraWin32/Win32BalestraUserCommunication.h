// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BUSER_COMM

#define _INC_W32_BUSER_COMM

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraConfiguration.h"

namespace BalestraEngine
{
	class Win32BalestraUserCommunication : public BalestraUserCommunication
	{
		public:
			Win32BalestraUserCommunication();
			Win32BalestraUserCommunication(Win32BalestraConfiguration* config);
			~Win32BalestraUserCommunication();

			virtual void consoleWarningMessage(std::string message);
			virtual void consoleErrorMessage(std::string message);
			virtual void consoleInfoMessage(std::string message);
			virtual void consoleExceptionMessage(BalestraException* ex);
			virtual void platformWarningMessage(std::string title, std::string message) override;
			virtual void platformErrorMessage(std::string title, std::string message) override;
			virtual void platformInfoMessage(std::string title, std::string message) override;
			virtual void platformExceptionMessage(BalestraException* ex) override;
		private:
			Win32BalestraConfiguration* configuration;
		protected:
	};
}

#endif