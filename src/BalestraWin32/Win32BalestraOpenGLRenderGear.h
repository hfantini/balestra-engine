// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BOPENGL_RENDERGEAR

#define _INC_BOPENGL_RENDERGEAR

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraOpenGLEnvironment.h"

namespace BalestraEngine
{
	class Win32BalestraOpenGLRenderGear : public BalestraRenderGear
	{
	public:

		// == VAR & CONST ===================================

		// == METHODS ======================================
		Win32BalestraOpenGLRenderGear(Win32BalestraOpenGLEnvironment* videoEnv);
		~Win32BalestraOpenGLRenderGear();

		void startDraw() override;
		void draw2DRect(Balestra2DRect* rect) override;
		void draw2DText(Balestra2DText* text) override;
		void draw2DSprite(Balestra2DSprite* sprite) override;
		void clearRenderTarget(B32ARGBColorFloat* color) override;
		void stopDraw() override;

	private:
	protected:

		Win32BalestraOpenGLEnvironment* win32OpenGLEnvironment;

	};
}

#endif