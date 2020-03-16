// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BOPENGL_ENV

#define _INC_BOPENGL_ENV

#include "Win32BalestraPrecompiledHeader.h"
#include "IWin32BalestraDevice.h"

namespace BalestraEngine
{
	class Win32BalestraOpenGLEnvironment : public BalestraEnvironmentVideo, public IWin32BalestraDevice
	{
		public:

			// == METHODS ======================================
			Win32BalestraOpenGLEnvironment(BalestraConfiguration* config);
			~Win32BalestraOpenGLEnvironment();

			virtual void initDevice() override;
			virtual B_BOOL isCompatible() override;
			virtual BalestraRenderGear* createRenderGear() override;
			virtual void cleanDevice() override;
			virtual void cleanRenderTarget(B32ARGBColorFloat* color) override;

			// == EVENTS =======================================
			void resize() override;

			// == GETTERS AND SETTERS ==========================

			HDC getGLContext();

		private:

			// == VAR & CONST ===================================

		protected:

			// == GETTERS AND SETTERS ==========================
			Win32BalestraConfiguration* getW32Configuration() override;

			//OPENGL VAR
			HDC context;
			HGLRC rContext;

			int pixelFormat;
	};
}

#endif