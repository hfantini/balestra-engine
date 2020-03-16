// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#define _USE_VIDEO_D2D
#define _USE_SOUND_XAUDIO

#include "PCHeader.h"
#include "TestWorld.h"

using namespace BalestraEngine;

Win32BalestraEnvironment* gameEnvironment;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
	BalestraInitStructure initStructure;

	initStructure.pInstance = hInstance;
	initStructure.pWindowWidth = 800;
	initStructure.pWindowHeight = 600;
	initStructure.pWindowX = 75;
	initStructure.pWindowY = 50;
	initStructure.pUseCustomIcon = B_TRUE;
	initStructure.pIconPath = "bIcon.ico";
	initStructure.pRunOnBackground = B_TRUE;
	initStructure.dImageDecoderInterface = BIMAGEDECODER_DEVIL;
	initStructure.gtRunning = B_TRUE;
	initStructure.gtMode = GAMETIME_FIXED_TIME_STEP;
	initStructure.gtTargetFPS = GAMETIME_DEFAULT_TARGET_FPS;
	initStructure.gtMaxFrameSkip = GAMETIME_DEFAULT_MAX_FRAMESKIP;
	initStructure.dbgMode = B_TRUE;
	initStructure.iAllowKeyboard = B_TRUE;
	initStructure.iAllowMouse = B_TRUE;
	initStructure.inputInterface = BINPUT_WIN32_PLATFORM;
	initStructure.inputType = BINPUT_TYPE_KEYBOARD_MOUSE;
	initStructure.gVideoInterface = BVIDEO_WIN32_OPENGL;
	initStructure.gOnResize = BVIDEO_ONRESIZE_STRETCH;
	initStructure.gVideoMode = BVIDEO_MODE_WINDOWED;
	initStructure.sAudioInterface = BAUDIO_WIN32_NO_SOUND;

	TestWorld* myTestWorld = new TestWorld();

	try
	{
		//_CrtSetBreakAlloc(150);

		gameEnvironment = new Win32BalestraEnvironment(initStructure);
		gameEnvironment->initEnvironment();
		gameEnvironment->setCurrentWorld(myTestWorld);
		myTestWorld->loadContent();
		gameEnvironment->runEnvironment();

		_CrtDumpMemoryLeaks();
		
	}
	catch (BalestraException* ex)
	{
		Win32BalestraUserCommunication comm = Win32BalestraUserCommunication();
		comm.platformExceptionMessage(ex);

		myTestWorld->unloadContent();
	}
}

