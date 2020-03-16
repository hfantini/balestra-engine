// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCONFIGURATION_DECODER

#define _INC_BCONFIGURATION_DECODER

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraConfigurationDecoder
	{
		public:

			// == METHODS ======================================

			// == GETTERS AND SETTERS ==========================
			int getImageDecoderInterface();
			void setImageDecoderInterface(int imageDecoderInterface);

		private:

		protected:

			// == VAR & CONST ===================================
			int imageDecoderInterface;

	};
}

#endif