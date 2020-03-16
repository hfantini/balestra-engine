// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BEXCEPTION

#define _INC_BEXCEPTION

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	// == GLOBAL DEFINITIONS
	// =====================================================

	// == STRUCT
	// =====================================================

	// == CLASS
	// =====================================================
	
	class BalestraException
	{
		public:

			// == METHODS ======================================
			BalestraException(std::string message, std::string systemMessage, std::string solution);

			// == GETTERS AND SETTERS ==========================
			virtual std::string getMessage();
			virtual std::string getSystemMessage();
			virtual std::string getSolution();

		private:

			// == VAR & CONST ===================================
			std::string message = "An unexpected error happened and the program can't continue.";
			std::string systemMessage = "The cause is unknown";
			std::string solution = "Don't have any known solution. Talk with the responsible programmer.";

		protected:
	};
}

#endif