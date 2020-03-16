// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraOpenGLEnvironment.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraConfigurationPlatform.h"
#include "Win32BalestraOpenGLRenderGear.h"

namespace BalestraEngine
{

	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraOpenGLEnvironment::Win32BalestraOpenGLEnvironment(BalestraConfiguration* config) : BalestraEnvironmentVideo(config)
	{

	}

	Win32BalestraOpenGLEnvironment::~Win32BalestraOpenGLEnvironment()
	{
		cleanDevice();
	}

	B_BOOL Win32BalestraOpenGLEnvironment::isCompatible()
	{
		return B_TRUE;
	}

	void Win32BalestraOpenGLEnvironment::initDevice()
	{
		PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),  /* size */
			1,                              /* version */
			PFD_SUPPORT_OPENGL |
			PFD_DRAW_TO_WINDOW |
			PFD_DOUBLEBUFFER,               /* support double-buffering */
			PFD_TYPE_RGBA,                  /* color type */
			16,                             /* prefered color depth */
			0, 0, 0, 0, 0, 0,               /* color bits (ignored) */
			0,                              /* no alpha buffer */
			0,                              /* alpha bits (ignored) */
			0,                              /* no accumulation buffer */
			0, 0, 0, 0,                     /* accum bits (ignored) */
			16,                             /* depth buffer */
			0,                              /* no stencil buffer */
			0,                              /* no auxiliary buffers */
			PFD_MAIN_PLANE,                 /* main layer */
			0,                              /* reserved */
			0, 0, 0,                        /* no layer, visible, damage masks */
		};

		Win32BalestraConfiguration* w32Config = static_cast<Win32BalestraConfiguration*>(configuration);
		
		context = GetDC(w32Config->getPlatformConfiguration()->getMainWindowHandle());

		int  letWindowsChooseThisPixelFormat;
		letWindowsChooseThisPixelFormat = ChoosePixelFormat(context, &pfd);
		SetPixelFormat(context, letWindowsChooseThisPixelFormat, &pfd);

		rContext = wglCreateContext(context);
		wglMakeCurrent(context, rContext);

		//DEFINING USER CONFIGURATIONS

		if (w32Config->getVideoConfiguration()->getVideoMode() == BVIDEO_MODE_FULLSCREEN)
		{
			DEVMODE dMode;

			memset(&dMode, 0, sizeof(DEVMODE));
			dMode.dmSize = sizeof(DEVMODE);
			dMode.dmPelsWidth = 800;
			dMode.dmPelsHeight = 600;
			dMode.dmBitsPerPel = 32;
			dMode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

			if (ChangeDisplaySettings(&dMode, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
			{
				throw new BalestraVideoException("Failed at process fullscreen mode", "Unknown error", "");
			}
		}

		//DEFINING COORDINATES SYSTEM

		int wWidth = w32Config->getPlatformConfiguration()->getWindowRect()->getWidth();
		int wHeight = w32Config->getPlatformConfiguration()->getWindowRect()->getHeight();

		glViewport(0, 0, wWidth, wHeight);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluOrtho2D(0, wWidth, wHeight, 0);

		//ENABLING FEATURES
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);

		//INITIALIZING FREETYPE LIB
		

	}

	BalestraRenderGear* Win32BalestraOpenGLEnvironment::createRenderGear()
	{
		return new Win32BalestraOpenGLRenderGear(this);
	}

	void Win32BalestraOpenGLEnvironment::cleanDevice()
	{
		wglDeleteContext(rContext);
	}

	void Win32BalestraOpenGLEnvironment::cleanRenderTarget(B32ARGBColorFloat* color)
	{
		glClearColor(color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	// == IMPLEMENTATION: Events
	// =====================================================
	void Win32BalestraOpenGLEnvironment::resize()
	{
		BRect* rect = getW32Configuration()->getPlatformConfiguration()->getWindowRect();
		glViewport(0, 0, rect->getWidth(), rect->getHeight());
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================
	Win32BalestraConfiguration* Win32BalestraOpenGLEnvironment::getW32Configuration()
	{
		return static_cast<Win32BalestraConfiguration*>(configuration);
	}

	HDC Win32BalestraOpenGLEnvironment::getGLContext()
	{
		return context;
	}

}