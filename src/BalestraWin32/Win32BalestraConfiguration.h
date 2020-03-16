// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BCONFIGURATION

#define _INC_W32_BCONFIGURATION

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	// == GLOBAL DEFINITIONS
	// =====================================================

	// == STRUCT
	// =====================================================

	// == CLASS
	// =====================================================
	
	class Win32BalestraConfigurationInput;
	class Win32BalestraConfigurationPlatform;

	class Win32BalestraConfiguration : public BalestraConfiguration
	{
		public:

			// == METHODS =======================================
			Win32BalestraConfiguration();
			~Win32BalestraConfiguration();

			// == GETTERS & SETTERS =============================
			Win32BalestraConfigurationPlatform* getPlatformConfiguration();
			Win32BalestraConfigurationInput* getWin32InputConfiguration();

		private:

		protected:

			// == VAR & CONST =================================== 
			Win32BalestraConfigurationPlatform* platformConfiguration;
			


	};
}

#endif