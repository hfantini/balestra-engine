
// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BALESTRA_IMAGE

#define _INC_BALESTRA_IMAGE

#include "BalestraPrecompiledHeader.h"
#include "IBalestraResource.h"
#include "BalestraDoubleVector.h"

namespace BalestraEngine
{
	class BalestraImage : IBalestraResource
	{
		public:

			// == METHODS ======================================

			BalestraImage();
			~BalestraImage();
			
			void unloadResource() override;

			// == GETTERS AND SETTERS ==========================

			BDoubleVector getSize();
			void setSize(BDoubleVector vector);
			std::string getPath();
			void setPath(std::string path);

		private:

		protected:


			// == VAR & CONST ===================================

			BDoubleVector size = BDoubleVector(0,0);
			std::string path = "";
	};
}

#endif