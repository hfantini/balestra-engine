// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BXAUDIO2_UTILS

#define _INC_W32_BXAUDIO2_UTILS

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	#define fourccRIFF 'FFIR'
	#define fourccDATA 'atad'
	#define fourccFMT ' tmf'
	#define fourccWAVE 'EVAW'
	#define fourccXWMA 'AMWX'
	#define fourccDPDS 'sdpd'

	class Win32BalestraXAudio2Utils
	{
		public:

			// == METHODS ======================================
			static HRESULT findChunk(HANDLE file, DWORD fourCC, DWORD& dwChunkSize, DWORD& dwChunkDataPosition);
			static HRESULT readChunkData(HANDLE file, void * buffer, DWORD bufferSize, DWORD bufferOffset);

		private:
		protected:
	};
}

#endif