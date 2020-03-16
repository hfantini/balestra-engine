// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =========================================================

#ifndef _INC_W32_BENVIRONMENT

#define _INC_W32_BENVIRONMENT

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraUserCommunication.h"


namespace BalestraEngine
{
	// == GLOBAL DEFINITIONS
	// =====================================================

	// == STRUCT
	// =====================================================

	struct BalestraInitStructure
	{
		int pWindowWidth;
		int pWindowHeight;
		int pWindowX;
		int pWindowY;
		int pShowMouseCursor = B_TRUE;
		B_BOOL pRunOnBackground;
		HINSTANCE pInstance;
		B_BOOL pUseCustomIcon;
		std::string pIconPath;
		int dImageDecoderInterface;
		int gtMode;
		B_BOOL gtRunning;
		int gtTargetFPS;
		int gtMaxFrameSkip;
		B_BOOL dbgMode;
		B_BOOL iAllowMouse;
		B_BOOL iAllowKeyboard;
		int inputInterface;
		int inputType;
		int gVideoInterface;
		int gOnResize;
		int gVideoMode;
		int sAudioInterface;
	};

	// == CLASS
	// =====================================================

	class Win32BalestraPlatformInput;

	class Win32BalestraEnvironment : public BalestraEnvironment
	{

	public:

		// == VAR & CONST===================================

		// == METHODS ======================================
		Win32BalestraEnvironment(BalestraInitStructure initStructure);
		~Win32BalestraEnvironment();

		void initEnvironment() override;
		void runEnvironment() override;
		void updateOptions() override;
		void exitGame() override;

		// == EVENTS =======================================

		// == GETTERS AND SETTERS ==========================
		Win32BalestraConfiguration* getWin32Configuration();

		private:

			// == GETTERS AND SETTERS ===========================
			BalestraInitStructure initStructure;
			Win32BalestraPlatformInput* getWin32PlatformInput();
			virtual void destroyEnvironment() override;

		protected:

			// == VAR & CONST ===================================

			HCURSOR defaultCursor;

			// == METHODS =======================================
			static LRESULT CALLBACK wndProc(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
			void processWndMessages(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
			void createWindow();
			void messageLoop();
			void destroyWindow();
	};
}

#endif