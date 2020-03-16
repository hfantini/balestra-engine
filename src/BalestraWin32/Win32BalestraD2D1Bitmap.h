// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class Win32BalestraD2D1Bitmap : public BalestraImage
	{
		public:

			// == METHODS ======================================
			Win32BalestraD2D1Bitmap();
			~Win32BalestraD2D1Bitmap();

			void unloadResource() override;

			// == GETTERS AND SETTERS ==========================
			ID2D1Bitmap* getSource();
			void setSource(ID2D1Bitmap* source);

		private:

			ID2D1Bitmap* source;

		protected:

			

			// == VAR & CONST ===================================
			
	};
}