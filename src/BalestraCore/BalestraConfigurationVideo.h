// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCONFIGURATION_VIDEO

#define _INC_BCONFIGURATION_VIDEO
#include "BalestraPrecompiledHeader.h"
#include "BalestraConstants.h"

namespace BalestraEngine
{
	// == GLOBAL DEFINITIONS
	// =====================================================

	// == STRUCT
	// =====================================================

	// == CLASS
	// =====================================================

	class BalestraConfigurationVideo
	{

	public:

		// == METHODS ======================================

		// == GETTERS AND SETTERS ==========================

		int getVideoInterface();
		void setVideoInterface(int interfaceValue);
		int getScreenWidth();
		void setScreenWidth(int width);
		int getScreenHeight();
		void setScreenHeight(int height);
		int getOnResize();
		void setOnResize(int resizeMode);
		int getVideoMode();
		void setVideoMode(int videoMode);

	private:

		// == VAR & CONST ==================================
		int videoInterface = 0;
		int screenWidth = RESOLUTION_DEFAULT_WIDTH;
		int screenHeight = RESOLUTION_DEFAULT_HEIGHT;
		int onResize = BVIDEO_ONRESIZE_STRETCH;
		int videoMode = BVIDEO_MODE_FULLSCREEN;

	protected:

	};
}

#endif