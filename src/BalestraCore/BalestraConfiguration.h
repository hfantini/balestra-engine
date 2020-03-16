// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCONFIGURATION

#define _INC_BCONFIGURATION

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	// == GLOBAL DEFINITIONS
	// =====================================================

	// == STRUCT
	// =====================================================

	// == CLASS
	// =====================================================

	class BalestraConfigurationVideo;
	class BalestraConfigurationSound;
	class BalestraConfigurationInput;
	class BalestraConfigurationGameTime;
	class BalestraConfigurationDebug;
	class BalestraConfigurationDecoder;

	class BalestraConfiguration
	{
		public:

			// == METHODS ======================================
			BalestraConfiguration();
			~BalestraConfiguration();

			// == GETTERS AND SETTERS ==========================
			BalestraConfigurationVideo* getVideoConfiguration();
			BalestraConfigurationSound* getSoundConfiguration();
			BalestraConfigurationInput* getInputConfiguration();
			BalestraConfigurationGameTime* getGameTimeConfiguration();
			BalestraConfigurationDebug* getDebugConfiguration();
			BalestraConfigurationDecoder* getDecoderConfiguration();

		private:

		protected:

			// == VAR & CONST ==================================
			BalestraConfigurationVideo* videoConfiguration;
			BalestraConfigurationSound* soundConfiguration;
			BalestraConfigurationInput* inputConfiguration;
			BalestraConfigurationGameTime* gameTimeConfiguration;
			BalestraConfigurationDebug* debugConfiguration;
			BalestraConfigurationDecoder* decoderConfiguration;
			

	};
}

#endif