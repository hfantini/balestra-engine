// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BENVIRONMENT_DSOUND

#define _INC_BENVIRONMENT_DSOUND

#include "Win32BalestraPrecompiledHeader.h"
#include "IWin32BalestraDevice.h"

namespace BalestraEngine
{
	class Win32BalestraConfiguration;

	class Win32BalestraXAudio2Environment : public BalestraEnvironmentSound, public IWin32BalestraDevice
	{
		public:

			// == METHODS ======================================

			Win32BalestraXAudio2Environment(Win32BalestraConfiguration* config);
			~Win32BalestraXAudio2Environment();

			void initDevice() override;
			B_BOOL isCompatible() override;
			BalestraSoundChannel* createSoundChannel() override;
			void cleanDevice() override;

			// == GETTERS AND SETTERS ==========================
			IXAudio2* getDevice();

		private:

			// == VAR & CONST ===================================
			Win32BalestraConfiguration* getW32Configuration();
			IXAudio2* device;
			IXAudio2MasteringVoice* masterVoice;


		protected:
	};
}

#endif