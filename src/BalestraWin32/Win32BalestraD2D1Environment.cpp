// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraD2D1Environment.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraD2D1RenderGear.h"
#include "Win32BalestraConfigurationPlatform.h"

namespace BalestraEngine
{

// == IMPLEMENTATION: Methods
// =====================================================

	Win32BalestraD2D1Environment::Win32BalestraD2D1Environment(BalestraConfiguration* config) : BalestraEnvironmentVideo(config)
	{
		renderGear = new Win32BalestraD2D1RenderGear(this);
	}

	Win32BalestraD2D1Environment::~Win32BalestraD2D1Environment()
	{
		cleanDevice();
	}

	B_BOOL Win32BalestraD2D1Environment::isCompatible()
	{
		int osCode = getW32Configuration()->getPlatformConfiguration()->getOperationalSystem();

		if (osCode != BPLATFORM_OS_VISTA && osCode != BPLATFORM_OS_VISTA_SP1 && osCode != BPLATFORM_OS_VISTA_SP2 && osCode != BPLATFORM_OS_WIN7 && osCode != BPLATFORM_OS_WIN7_SP1 && osCode != BPLATFORM_OS_WIN8 && osCode != BPLATFORM_OS_WIN8_1)
		{
			return B_FALSE;
		}

		return B_TRUE;
	}

	void Win32BalestraD2D1Environment::initDevice()
	{
		if (!isCompatible())
		{
			std::string sysMsg = "The current operational system (";
			sysMsg.append(Win32BalestraPlatformUtil::getOsSystemName(getW32Configuration()->getPlatformConfiguration()->getOperationalSystem()));
			sysMsg.append(") is incompatible with the video interface (Direct2D_1).");

			throw new BalestraVideoException("Error at iniatilizing the video component.", sysMsg, "");
		}

		HRESULT hr = S_OK;

		if (!gRenderTargetView)
		{
			RECT clientRect;

			GetClientRect(Win32BalestraD2D1Environment::getW32Configuration()->getPlatformConfiguration()->getMainWindowHandle(), &clientRect);
			Win32BalestraD2D1Environment::configuration->getVideoConfiguration()->setScreenWidth(clientRect.right - clientRect.left);
			Win32BalestraD2D1Environment::configuration->getVideoConfiguration()->setScreenHeight(clientRect.bottom - clientRect.top);

			// == CREATING D2D FACTORY ===================

			hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &gD2DFactory);

			if (FAILED(hr))
			{
				throw new BalestraVideoException("Error at create the D2D1 Factory", "", "");
			}

			// == GET DPI INFO ===========================
			FLOAT dpiX, dpiY;
			gD2DFactory->GetDesktopDpi(&dpiX, &dpiY);

			HWND handle = getW32Configuration()->getPlatformConfiguration()->getMainWindowHandle();

			D2D1_SIZE_U size = D2D1::SizeU((UINT)getW32Configuration()->getPlatformConfiguration()->getWindowRect()->getWidth(), (UINT)getW32Configuration()->getPlatformConfiguration()->getWindowRect()->getHeight());

			// == CREATING RENDER TARGET =================
			hr = gD2DFactory->CreateHwndRenderTarget(
				D2D1::RenderTargetProperties(),
				D2D1::HwndRenderTargetProperties(handle, size),
				&gRenderTargetView
				);

			if (FAILED(hr))
			{
				throw new BalestraVideoException("Error at create the D2D1 RenderTargetView", "", "");
			}

			// == CREATING BRUSHES =======================

			hr = gRenderTargetView->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &gDefaultSolidBrush);

			if (FAILED(hr))
			{
				throw new BalestraVideoException("Error at create the D2D1 Brush", "", "");
			}

			// == CREATING WRITE FACTORY =================

			hr = DWriteCreateFactory(
				DWRITE_FACTORY_TYPE_SHARED,
				__uuidof(writeFactory),
				reinterpret_cast<IUnknown **>(&writeFactory)
				);

			if (FAILED(hr))
			{
				throw new BalestraVideoException("Error at create the DirectWrite Factory", "", "");
			}
		
		}
	}

	BalestraRenderGear* Win32BalestraD2D1Environment::createRenderGear()
	{
		return new Win32BalestraD2D1RenderGear(this);
	}

	void Win32BalestraD2D1Environment::cleanDevice()
	{
		BalestraEnvironmentVideo::cleanDevice();

		if (gRenderTargetView)
		{
			gRenderTargetView->Release();
		}

		if (gD2DFactory)
		{
			gD2DFactory->Release();
		}

		if (writeFactory)
		{
			writeFactory->Release();
		}

		if (renderGear)
		{
			delete renderGear;
		}
	}

	void Win32BalestraD2D1Environment::cleanRenderTarget(B32ARGBColorFloat* color)
	{
		
		_D3DCOLORVALUE colors[] = { color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha() };
		gRenderTargetView->Clear(colors);
	}

	// == IMPLEMENTATION: Events
	// =====================================================
	void Win32BalestraD2D1Environment::resize()
	{
		if (gRenderTargetView)
		{
			if (configuration->getVideoConfiguration()->getOnResize() == BVIDEO_ONRESIZE_RESIZE)
			{
				BRect* rect = getW32Configuration()->getPlatformConfiguration()->getWindowRect();
				gRenderTargetView->Resize(D2D1::SizeU( (UINT) rect->getWidth(), (UINT) rect->getHeight()));
			}
		}
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================
	IDWriteFactory* Win32BalestraD2D1Environment::getWriteFactory()
	{
		return Win32BalestraD2D1Environment::writeFactory;
	}

	ID2D1HwndRenderTarget* Win32BalestraD2D1Environment::getRenderTargetView()
	{
		return Win32BalestraD2D1Environment::gRenderTargetView;
	}

	ID2D1SolidColorBrush* Win32BalestraD2D1Environment::getDefaultSolidBrush()
	{
		return Win32BalestraD2D1Environment::gDefaultSolidBrush;
	}

	Win32BalestraConfiguration* Win32BalestraD2D1Environment::getW32Configuration()
	{
		return static_cast<Win32BalestraConfiguration*>(configuration);
	}
}