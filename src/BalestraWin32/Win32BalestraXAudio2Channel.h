// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_XAUDIO_CHANNEL

#define _INC_W32_XAUDIO_CHANNEL

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class Win32BalestraXAudio2Environment;

	class Win32BalestraXAudio2Channel : public BalestraSoundChannel
	{
		public:

			// == METHODS ======================================
			Win32BalestraXAudio2Channel(Win32BalestraXAudio2Environment* audioEnv);
			~Win32BalestraXAudio2Channel();

			void initDevice() override;
			B_BOOL isCompatible() override;
			void play() override;
			void stop() override;
			void pause() override;
			void cleanDevice() override;

			// == GETTERS AND SETTERS ==========================
			void setCurrentSound(BalestraSound* sound) override;

		private:

			// == VAR & CONST ===================================
			Win32BalestraXAudio2Environment* audioEnv;
			IXAudio2SourceVoice* sourceVoice;

		protected:
	};
}

#endif