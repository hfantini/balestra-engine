// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BXAUDIO_LOADER

#define _INC_W32_BXAUDIO_LOADER

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class Win32BalestraXAudio2SoundLoader : public BalestraSoundLoader
	{
		public:

			Win32BalestraXAudio2SoundLoader();
			~Win32BalestraXAudio2SoundLoader();

			BalestraSound* loadSound(std::string soundPath, int fileType) override;
			void unloadSound(BalestraSound* sound) override;

		private:

		protected:
	};
}

#endif