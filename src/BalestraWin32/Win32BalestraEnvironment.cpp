// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraEnvironment.h"
#include "Win32BalestraD2D1Environment.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraPlatformInput.h"
#include "Win32BalestraPlatformInput.h"
#include "Win32BalestraConfigurationPlatform.h"
#include "Win32BalestraConfigurationInput.h"
#include "Win32BalestraEnvironmentResource.h"
#include "Win32BalestraPlatformException.h"
#include "Win32BalestraGameTime.h"
#include "Win32BalestraXAudio2Environment.h"
#include "Win32BalestraOpenGLEnvironment.h"

namespace BalestraEngine
{
	// == GLOBAL DEFINITIONS
	// =====================================================

	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraEnvironment::Win32BalestraEnvironment(BalestraInitStructure initStructure)
	{
		Win32BalestraEnvironment::initStructure = initStructure;
	}

	Win32BalestraEnvironment::~Win32BalestraEnvironment()
	{
		destroyEnvironment();
	}

	LRESULT CALLBACK Win32BalestraEnvironment::wndProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
	{
		Win32BalestraEnvironment* bEnvironment;

		if (message == WM_NCCREATE)
		{
			bEnvironment = static_cast<Win32BalestraEnvironment*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
			SetLastError(0);

			if (!SetWindowLongPtr(windowHandle, GWL_USERDATA, reinterpret_cast<LONG_PTR>(bEnvironment)))
			{
				if (GetLastError() != 0)
				{
					throw new Win32BalestraPlatformException("Error at defining the default WNDProc function", "", "");
				}
			}
		}
		else
		{
			bEnvironment = reinterpret_cast<Win32BalestraEnvironment*>(GetWindowLongPtr(windowHandle, GWL_USERDATA));
		}

		if (bEnvironment)
		{
			bEnvironment->processWndMessages(windowHandle, message, wParam, lParam);
		}

		return DefWindowProc(windowHandle, message, wParam, lParam);
	}

	void Win32BalestraEnvironment::processWndMessages(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
	{
		// == GERAL MESSAGES TRATMENT
		// ===================================================

		switch (message)
		{
			case WM_DESTROY:
				PostQuitMessage(1);
				break;

			case WM_SIZE:
				getWin32Configuration()->getPlatformConfiguration()->getWindowRect()->setWidth(LOWORD(lParam));
				getWin32Configuration()->getPlatformConfiguration()->getWindowRect()->setHeight(HIWORD(lParam));
				getVideoEnvironment()->resize();
				break;
		}
	}

	void Win32BalestraEnvironment::createWindow()
	{
		HWND windowHandle = { 0 };
		WNDCLASSEX wc;

		int wWidth = (int)Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->getWindowRect()->getWidth();
		int wHeight = (int)Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->getWindowRect()->getHeight();
		int wPosX = (int)Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->getWindowRect()->getX();
		int wPosY = (int)Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->getWindowRect()->getY();
		DWORD windowStyle;

		ZeroMemory(&wc, sizeof(WNDCLASSEX));

		if (configuration->getVideoConfiguration()->getVideoMode() == BVIDEO_MODE_WINDOWED)
		{
			windowStyle = WS_OVERLAPPEDWINDOW;
		}
		else if (configuration->getVideoConfiguration()->getVideoMode() == BVIDEO_MODE_WINDOWED_FS)
		{
			windowStyle = WS_POPUP | WS_VISIBLE | WS_SYSMENU;
		}
		else
		{
			windowStyle = WS_POPUP | WS_VISIBLE | WS_SYSMENU;
		}

		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = Win32BalestraEnvironment::wndProc;
		wc.hInstance = Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->getWin32Instance();

		if (getWin32Configuration()->getPlatformConfiguration()->getUseCustomIco() == B_TRUE)
		{
			wc.hIcon = getWin32Configuration()->getPlatformConfiguration()->getAppIcon();
		}

		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.lpszClassName = L"BalestraWindowClass";

		RegisterClassEx(&wc);

		windowHandle = CreateWindowEx(NULL,
			L"BalestraWindowClass",
			L"BalestraGame",
			windowStyle,
			wPosX,
			wPosY,
			wWidth,
			wHeight,
			NULL,
			NULL,
			Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->getWin32Instance(),
			this);

		if (Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->getUseCustomIco() == B_TRUE)
		{
			SendMessage(windowHandle, WM_SETICON, ICON_SMALL, (LPARAM)getWin32Configuration()->getPlatformConfiguration()->getAppIcon());
			SendMessage(windowHandle, WM_SETICON, ICON_BIG, (LPARAM)getWin32Configuration()->getPlatformConfiguration()->getAppIcon());
		}

		Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->setMainWindowHandle(windowHandle);
	}

	void Win32BalestraEnvironment::initEnvironment()
	{
		try
		{
			BalestraEnvironment::initEnvironment();

			// == DEFINING RESOURCE OBJECTS =====================
			// ==================================================

			Win32BalestraEnvironment::configuration = new Win32BalestraConfiguration();

			// SETS ALL CONFIGURATION PROPERTIES TO THE CONTROL OBJECTS

			// -- DEBUG ------------------
			Win32BalestraEnvironment::getWin32Configuration()->getDebugConfiguration()->setDebugMode(initStructure.dbgMode);

			if (initStructure.dbgMode == B_TRUE)
			{
				#define BALESTRA_DEBUG
			}

			// -- PLATAFORM --------------
			defaultCursor = LoadCursor(NULL, IDC_ARROW);
			
			Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->setWindowRect(BRect(
				(float)initStructure.pWindowX,
				(float)initStructure.pWindowY,
				(float)initStructure.pWindowWidth,
				(float)initStructure.pWindowHeight));

			Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->setRunOnBackground(initStructure.pRunOnBackground);
			Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->setWin32Instance(initStructure.pInstance);
			Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->setMouseCursorVisibility(initStructure.pShowMouseCursor);

			if (initStructure.pUseCustomIcon == B_TRUE)
			{
				getWin32Configuration()->getPlatformConfiguration()->setUseCustomIco(B_TRUE);
				getWin32Configuration()->getPlatformConfiguration()->setAppIcon((HICON)LoadImageA(NULL, initStructure.pIconPath.c_str(), IMAGE_ICON, 32, 32, LR_LOADFROMFILE));
			}
			else
			{
				getWin32Configuration()->getPlatformConfiguration()->setUseCustomIco(B_FALSE);
			}

			// -- VIDEO ------------------
			
			//videoInterface
			Win32BalestraEnvironment::getWin32Configuration()->getVideoConfiguration()->setVideoInterface(initStructure.gVideoInterface);

			//onResize
			if (initStructure.gOnResize != 0)
			{
				getWin32Configuration()->getVideoConfiguration()->setOnResize( initStructure.gOnResize );
			}

			//videoMode
			if (initStructure.gVideoMode != 0)
			{
				getWin32Configuration()->getVideoConfiguration()->setVideoMode(initStructure.gVideoMode);
			}

			// -- SOUND ------------------
			Win32BalestraEnvironment::getWin32Configuration()->getSoundConfiguration()->setSoundInterface(initStructure.sAudioInterface);

			// -- RESOURCE ---------------
			Win32BalestraEnvironment::getWin32Configuration()->getDecoderConfiguration()->setImageDecoderInterface(initStructure.dImageDecoderInterface);

			// -- INPUT ------------------
			Win32BalestraEnvironment::getWin32Configuration()->getWin32InputConfiguration()->setInputType(initStructure.inputType);
			Win32BalestraEnvironment::getWin32Configuration()->getWin32InputConfiguration()->setInputInterface(initStructure.inputInterface);
			Win32BalestraEnvironment::getWin32Configuration()->getWin32InputConfiguration()->setAllowMouse(initStructure.iAllowMouse);
			Win32BalestraEnvironment::getWin32Configuration()->getWin32InputConfiguration()->setAllowKeyboard(initStructure.iAllowKeyboard);

			// -- GAME TIME --------------
			Win32BalestraEnvironment::getWin32Configuration()->getGameTimeConfiguration()->setMode(initStructure.gtMode);
			Win32BalestraEnvironment::getWin32Configuration()->getGameTimeConfiguration()->setRunning(initStructure.gtRunning);
			Win32BalestraEnvironment::getWin32Configuration()->getGameTimeConfiguration()->setTargetFPS(initStructure.gtTargetFPS);
			Win32BalestraEnvironment::getWin32Configuration()->getGameTimeConfiguration()->setMaxFrameSkip(initStructure.gtMaxFrameSkip);

			Win32BalestraEnvironment::getWin32Configuration()->getPlatformConfiguration()->gatherSystemInformation();

			// ==  RESOURCE OBJECTS =============================
			// ==================================================

			CoInitialize(NULL);

			// -- COMM ------------------- 
			userComm = new Win32BalestraUserCommunication(getWin32Configuration());

			// -- VIDEO ------------------
			switch (Win32BalestraEnvironment::getWin32Configuration()->getVideoConfiguration()->getVideoInterface())
			{
				case BVIDEO_WIN32_DIRECT2D_1:
					videoEnvironment = new Win32BalestraD2D1Environment(getWin32Configuration());
					break;

				case BVIDEO_WIN32_OPENGL:
					videoEnvironment = new Win32BalestraOpenGLEnvironment(getWin32Configuration());
					break;

				default:
					throw new BalestraVideoException("Error at instantiating the video interface.", "The defined video interface is invalid.", "Check if the defined video interface is valid and try again.");
					break;
			}

			// -- SOUND ------------------
			switch (Win32BalestraEnvironment::getWin32Configuration()->getSoundConfiguration()->getSoundInterface())
			{
				case BAUDIO_WIN32_NO_SOUND:
					break;

				case BAUDIO_WIN32_XAUDIO2:
					 soundEnvironment = new Win32BalestraXAudio2Environment(getWin32Configuration());
					 break;

				default:
					throw new BalestraVideoException("Error at instantiating the sound interface.", "The defined sound interface is invalid.", "Check if the defined sound interface is valid and try again.");
					break;
			}

			// -- INPUT ------------------
			switch (Win32BalestraEnvironment::getWin32Configuration()->getInputConfiguration()->getInputInterface())
			{
				case BINPUT_WIN32_PLATFORM:
						inputEnvironment = new Win32BalestraPlatformInput(getWin32Configuration());
						break;

				default:
					throw new BalestraInputException("Error at instantiating the input interface.", "The defined input interface is invalid.", "Check if the defined input interface is valid and try again.");
					break;
			}

			// -- RESOURCE ---------------
			Win32BalestraEnvironment::resourceEnvironment = new Win32BalestraEnvironmentResource(configuration, videoEnvironment);

			// -- GAME TIME --------------
			Win32BalestraEnvironment::gameTime = new Win32BalestraGameTime(getWin32Configuration());

			// ==  INITIALIZING RESOURCE OBJECTS ================
			// ==================================================

			Win32BalestraEnvironment::createWindow();

			if (Win32BalestraEnvironment::inputEnvironment)
			{
				Win32BalestraEnvironment::inputEnvironment->initDevice();
			}

			if (Win32BalestraEnvironment::videoEnvironment)
			{
				Win32BalestraEnvironment::videoEnvironment->initDevice();
			}

			if (Win32BalestraEnvironment::soundEnvironment)
			{
				Win32BalestraEnvironment::soundEnvironment->initDevice();
			}

			if (Win32BalestraEnvironment::resourceEnvironment)
			{
				Win32BalestraEnvironment::resourceEnvironment->initDevice();
			}
		}

		catch (BalestraException* ex)
		{
			destroyEnvironment();
			throw ex;
		}
	}

	void Win32BalestraEnvironment::messageLoop()
	{
		try
		{
			MSG msg = { 0 };

			Win32BalestraEnvironment::gameTime->initDevice();

			PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);

			while (msg.message != WM_QUIT)
			{
				while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				
				// -- CHECKING THE BACKGROUND RUNNING OPTION ----------------

				if (getWin32Configuration()->getPlatformConfiguration()->getRunOnBackground() == B_FALSE
					&& GetFocus() != getWin32Configuration()->getPlatformConfiguration()->getMainWindowHandle())
				{
					getConfiguration()->getGameTimeConfiguration()->setRunning(B_FALSE);
				}
				else
				{
					getConfiguration()->getGameTimeConfiguration()->setRunning(B_TRUE);
				}

				// -- RENDERING ---------------------------------------------

				if (Win32BalestraEnvironment::videoEnvironment && Win32BalestraEnvironment::getCurrentWorld())
				{
					gameTime->tickTime(getCurrentWorld());
				}
			}

			Win32BalestraEnvironment::destroyEnvironment();
		}
		catch (BalestraException* ex)
		{
			destroyEnvironment();
			throw ex;
		}
	}

	void Win32BalestraEnvironment::destroyWindow()
	{
		CloseWindow(getWin32Configuration()->getPlatformConfiguration()->getMainWindowHandle());
	}

	void Win32BalestraEnvironment::runEnvironment()
	{
		switch (getConfiguration()->getVideoConfiguration()->getVideoMode())
		{
			case BVIDEO_MODE_WINDOWED:
				ShowWindow(getWin32Configuration()->getPlatformConfiguration()->getMainWindowHandle(), 5);
				break;

			default:
				ShowWindow(getWin32Configuration()->getPlatformConfiguration()->getMainWindowHandle(), 3);
				break;
		}
		

		Win32BalestraEnvironment::messageLoop();
	}

	void Win32BalestraEnvironment::destroyEnvironment()
	{
		Win32BalestraEnvironment::destroyWindow();

		// == UNLOADING CURRENT WORLD
		if (currentWorld)
		{
			currentWorld->unloadContent();
			delete currentWorld;
			currentWorld = { 0 };
		}

		// == UNLOADING RESOURCES 
		// ============================================

		// -- VIDEO -----------------------------------

		if (videoEnvironment)
		{
			switch (Win32BalestraEnvironment::getWin32Configuration()->getVideoConfiguration()->getVideoInterface())
			{
				case BVIDEO_WIN32_DIRECT2D_1:
					delete dynamic_cast<Win32BalestraD2D1Environment*>(videoEnvironment);
					break;

				case BVIDEO_WIN32_OPENGL:
					delete dynamic_cast<Win32BalestraOpenGLEnvironment*>(videoEnvironment);
					break;

				default:
					throw new BalestraVideoException("Error at unloading the video interface.", "The defined video interface is invalid.", "Check if the defined video interface is valid and try again.");
					break;
			}
		}

		// -- SOUND -----------------------------------

		switch (Win32BalestraEnvironment::getWin32Configuration()->getSoundConfiguration()->getSoundInterface())
		{
			case BAUDIO_WIN32_NO_SOUND:
				break;

			case BAUDIO_WIN32_XAUDIO2:
				delete dynamic_cast<Win32BalestraXAudio2Environment*>(soundEnvironment);
				break;

			default:
				throw new BalestraVideoException("Error at instantiating the sound interface.", "The defined sound interface is invalid.", "Check if the defined sound interface is valid and try again.");
				break;
		}

		// -- INPUT -----------------------------------

		if (inputEnvironment)
		{
			switch (Win32BalestraEnvironment::getWin32Configuration()->getInputConfiguration()->getInputInterface())
			{
				case BINPUT_WIN32_PLATFORM:
					delete dynamic_cast<Win32BalestraPlatformInput*>(inputEnvironment);
					break;

				default:
					throw new BalestraInputException("Error at unloading the input interface.", "The defined input interface is invalid.", "Check if the defined input interface is valid and try again.");
					break;
			}
		}

		// -- RESOURCES -----------------------------------

		if (resourceEnvironment)
		{
			resourceEnvironment->cleanDevice();
			delete dynamic_cast<Win32BalestraEnvironmentResource*>(resourceEnvironment);
		}

		// -- USER COMMUNICATION INTERFACE ---------------------
		if (userComm)
		{
			delete dynamic_cast<Win32BalestraUserCommunication*>(userComm);
		}

		// -- BASE CLASS COMPONENTS ----------------------------
		BalestraEnvironment::destroyEnvironment();

		// -- CONFIGURATIONS -----------------------------------
		if (configuration)
		{
			delete static_cast<Win32BalestraConfiguration*>(configuration);
		}
	}

	void Win32BalestraEnvironment::updateOptions()
	{
		//MOUSE VISIBILITY
		if (getWin32Configuration()->getPlatformConfiguration()->getMouseCursorVisibility() == B_TRUE)
		{
			SetCursor(defaultCursor);
		}	
		else
		{
			SetCursor(NULL);
		}
	}

	void Win32BalestraEnvironment::exitGame()
	{
		PostQuitMessage(1);
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	Win32BalestraPlatformInput* Win32BalestraEnvironment::getWin32PlatformInput()
	{
		Win32BalestraPlatformInput* input = dynamic_cast<Win32BalestraPlatformInput*>(inputEnvironment);
		return input;
	}

	Win32BalestraConfiguration* Win32BalestraEnvironment::getWin32Configuration()
	{
		return static_cast<Win32BalestraConfiguration*>(configuration);
	}
}
