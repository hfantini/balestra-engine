// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BVIDEO_ENVIRONMENT

#define _INC_BVIDEO_ENVIRONMENT

#include "BalestraPrecompiledHeader.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	class BalestraRenderGear;
	class BalestraCamera;
	class B32ARGBColorFloat;
	class BDoubleVector;

	class BalestraEnvironmentVideo : public IBalestraDevice
	{
		public:

			BalestraEnvironmentVideo(BalestraConfiguration* configuration);

			// == METHODS ======================================
			virtual BalestraRenderGear* createRenderGear();
			virtual void cleanDevice() override;
			virtual void cleanRenderTarget(B32ARGBColorFloat* color);

			// == EVENTS =======================================
			virtual void resize();

			// == GETTERS AND SETTERS ==========================
			BalestraCamera* getCamera();

		private:

		protected:

			// == VAR & CONSTS =================================
			BalestraRenderGear* renderGear;
			BalestraCamera* camera;
	};
}


#endif