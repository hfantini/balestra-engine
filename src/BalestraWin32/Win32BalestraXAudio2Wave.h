// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_XAUDIO_WAVE

#define _INC_W32_XAUDIO_WAVE

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class Win32BalestraXAudio2Wave : public BalestraSound
	{
		public:

			// == GETTERS AND SETTERS ===========================
			XAUDIO2_BUFFER getSource();
			void setSource(XAUDIO2_BUFFER source);
			WAVEFORMATEXTENSIBLE getFormat();
			void setFormat(WAVEFORMATEXTENSIBLE source);

		private:

			// == VAR & CONST ===================================
			XAUDIO2_BUFFER buffer;
			WAVEFORMATEXTENSIBLE format;

		protected:
	};
}

#endif