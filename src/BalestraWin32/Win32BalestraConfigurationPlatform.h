// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BCONFIGURATION_platform

#define _INC_W32_BCONFIGURATION_platform

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	// == CLASS
	// =====================================================

	class Win32BalestraConfigurationPlatform : public BalestraConfigurationPlatform
	{
		public:
			
			// == VAR & CONST ===================================

			// == METHODS =======================================

			Win32BalestraConfigurationPlatform();
			~Win32BalestraConfigurationPlatform();
			void gatherSystemInformation() override;

			// == GETTERS AND SETTERS ===========================
			HINSTANCE getWin32Instance();
			void setWin32Instance(HINSTANCE hInstance);
			HWND getMainWindowHandle();
			void setMainWindowHandle(HWND windowHandle);
			BRect* getWindowRect();
			void setWindowRect(BRect rect);
			B_BOOL getRunOnBackground();
			void setRunOnBackground(B_BOOL value);
			B_BOOL getUseCustomIco();
			void setUseCustomIco(B_BOOL value);
			B_BOOL getMouseCursorVisibility();
			void setMouseCursorVisibility(B_BOOL visibility);
			HICON getAppIcon();
			void setAppIcon(HICON icon);
			int getOperationalSystem();

		private:

			// == VAR & CONST ===================================

			HINSTANCE win32Instance;
			HWND mainWindowHandle;
			BRect windowRect;
			B_BOOL runOnBackground;
			B_BOOL useCustomIco;
			B_BOOL mouseCursorVisibility;
			HICON appIcon;
			int operationalSystem;

			// == METHODS ======================================
			void gatherSOInfo();


		protected:
	};
}

#endif