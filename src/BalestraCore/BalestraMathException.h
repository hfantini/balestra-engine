// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION_MATH

#define _INC_BEXCEPTION_MATH

#include "BalestraException.h"

namespace BalestraEngine
{

	class BalestraMathException : public BalestraException
	{

		public:

			// == METHODS ======================================
			BalestraMathException(std::string message, std::string systemMessage, std::string solution) : BalestraException(message, systemMessage, solution){};

		private:
		protected:
	};

}

#endif