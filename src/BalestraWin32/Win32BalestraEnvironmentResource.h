// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BENVIRONMENT_RESOURCE

#define _INC_W32_BENVIRONMENT_RESOURCE

#include "Win32BalestraPrecompiledHeader.h"
#include "IWin32BalestraDevice.h"

namespace BalestraEngine
{
	class Win32BalestraEnvironmentResource : public BalestraEnvironmentResource, public IWin32BalestraDevice
	{
		public:

			// == METHODS ======================================

			Win32BalestraEnvironmentResource(BalestraConfiguration* configuration, BalestraEnvironmentVideo* videoEnvironment);
			void initDevice() override;
			B_BOOL isCompatible() override;
			void cleanDevice() override;

			BalestraImageLoader* createImageLoader() override;
			BalestraSoundLoader* createSoundLoader() override;
			BalestraFontLoader* createFontLoader() override;

		private:

			// == METHODS ======================================
			B_BOOL checkWICCompatibility();

		protected:

			// == GETTERS AND SETTERS ==========================
			Win32BalestraConfiguration* getW32Configuration() override;
	};
}

#endif