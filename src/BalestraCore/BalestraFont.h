// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BALESTRA_FONT

#define _INC_BALESTRA_FONT

#include "IBalestraResource.h"

namespace BalestraEngine
{

	class BalestraFont : IBalestraResource
	{
		public:

			BalestraFont();
			~BalestraFont();

			void unloadResource() override;

		private:
		protected:
	};

}

#endif