// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BDX2D_ENV

#define _INC_BDX2D_ENV

#include "Win32BalestraPrecompiledHeader.h"
#include "IWin32BalestraDevice.h"

namespace BalestraEngine
{
	class Win32BalestraConfiguration;
	class BalestraRenderGear;

	class Win32BalestraD2D1Environment : public BalestraEnvironmentVideo, public IWin32BalestraDevice
	{
		public:

			// == METHODS ======================================
			Win32BalestraD2D1Environment(BalestraConfiguration* config);
			~Win32BalestraD2D1Environment();

			virtual void initDevice() override;
			virtual B_BOOL isCompatible() override;
			virtual BalestraRenderGear* createRenderGear() override;
			virtual void cleanDevice() override;
			virtual void cleanRenderTarget(B32ARGBColorFloat* color) override;
			
			// == EVENTS =======================================
			void resize() override;

			// == GETTERS AND SETTERS ==========================
			ID2D1HwndRenderTarget* getRenderTargetView();
			IDWriteFactory* getWriteFactory();
			ID2D1SolidColorBrush* getDefaultSolidBrush();

		private:

			// == VAR & CONST ===================================
			ID2D1SolidColorBrush* gDefaultSolidBrush;
			ID2D1Factory* gD2DFactory;
			ID2D1HwndRenderTarget* gRenderTargetView;
			IDWriteFactory* writeFactory;

		protected:

			// == GETTERS AND SETTERS ==========================
			Win32BalestraConfiguration* getW32Configuration() override;
	};
}

#endif

