
// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BENVIRONMENT

#define _INC_BENVIRONMENT

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	// == GLOBAL DEFINITIONS
	// =====================================================

	// == STRUCT
	// =====================================================

	// == CLASS
	// =====================================================

	class BalestraWorld;
	class BalestraUserCommunication;
	class BalestraGameTime;
	class BalestraEnvironmentVideo;
	class BalestraEnvironmentResource;
	class BalestraConfiguration;
	class BalestraEnvironmentInput;
	class BalestraImageDecoder;
	class BalestraEnvironmentSound;

    class BalestraEnvironment
	{
		public:

			// == VAR & CONST ==================================
			~BalestraEnvironment();

			// == METHODS ======================================
			virtual void initEnvironment();
			virtual void runEnvironment();
			virtual void reloadEnvironment();
			virtual void updateOptions();
			virtual void destroyEnvironment();
			virtual void exitGame();

			// == EVENTS =======================================

			// == GETTERS AND SETTERS ==========================
			BalestraWorld* getCurrentWorld();
			void setCurrentWorld(BalestraWorld* world);
			virtual unsigned long getCurrentSystemTimeInMillis();
			BalestraConfiguration* getConfiguration();
			BalestraUserCommunication* getUserCommunicationInterface();
			BalestraEnvironmentVideo* getVideoEnvironment();
			BalestraEnvironmentSound* getSoundEnvironment();
			BalestraEnvironmentInput* getInputEnvironment();
			BalestraEnvironmentResource* getResourceEnvironment();

		private:

		protected:
			BalestraWorld* currentWorld;
			BalestraUserCommunication* userComm;
			BalestraConfiguration* configuration;
			BalestraEnvironmentVideo* videoEnvironment;
			BalestraEnvironmentSound* soundEnvironment;
			BalestraEnvironmentInput* inputEnvironment;
			BalestraGameTime* gameTime;
			BalestraEnvironmentResource* resourceEnvironment;
	};
}

#endif