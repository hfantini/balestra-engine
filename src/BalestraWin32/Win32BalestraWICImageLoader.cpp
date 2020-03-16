// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// ======================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraWICImageLoader.h"
#include "Win32BalestraD2D1Bitmap.h"
#include "Win32BalestraD2D1Environment.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraWICImageLoader::Win32BalestraWICImageLoader(BalestraConfiguration* configuration, BalestraEnvironmentVideo* videoEnvironment)
	{
		Win32BalestraWICImageLoader::configuration = configuration;
		Win32BalestraWICImageLoader::videoEnvironment = videoEnvironment;

		HRESULT hr;

		hr = CoCreateInstance
			(CLSID_WICImagingFactory1,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&WICFactory));

		if (FAILED(hr))
		{
			throw new BalestraResourceException("Error at create the WIC Factory", "", "");
		}
	}

	Win32BalestraWICImageLoader::~Win32BalestraWICImageLoader()
	{
		if (WICFactory)
		{
			WICFactory->Release();
		}
	}

	BalestraImage* Win32BalestraWICImageLoader::loadImage(BImageInfo imageInfo)
	{
		switch (configuration->getVideoConfiguration()->getVideoInterface())
		{
			case BVIDEO_WIN32_DIRECT2D_1:

				return loadImageDirect2D(imageInfo);
				break;

			default:

				throw new BalestraResourceException("Error at loading image.", "The video interface is unknown", "Check if the current video interface is valid.");
				break;
		}
	}

	BalestraImage* Win32BalestraWICImageLoader::loadImageDirect2D(BImageInfo imageInfo)
	{
		IWICBitmapDecoder* decoder = NULL;
		IWICFormatConverter* converter = NULL;
		IWICBitmapFrameDecode* decodedImage = NULL;
		IWICBitmapScaler* scaler;
		Win32BalestraD2D1Environment* video = static_cast<Win32BalestraD2D1Environment*>(videoEnvironment);

		float scaleFactorX = 1;
		float scaleFactorY = 1;
		UINT originalW = 0;
		UINT originalH = 0;

		HRESULT hr;

		std::string oldStr = imageInfo.imagePath;
		std::wstring wideStr = std::wstring(oldStr.begin(), oldStr.end());

	    hr = WICFactory->CreateDecoderFromFilename(
			wideStr.c_str(),
			NULL,
			GENERIC_READ,
			WICDecodeMetadataCacheOnDemand,
			&decoder);

		if (FAILED(hr))
		{
			std::string message = "Error at decoding the image: ";
			message.append(imageInfo.imagePath);

			_com_error err(hr);
			LPCTSTR sysMsg = err.ErrorMessage();
			std::wstring WsysMsg = sysMsg;
			std::string sysMsgA = std::string(WsysMsg.begin(), WsysMsg.end());

			throw new BalestraResourceException(message, sysMsgA, "Check if the Decoding function parameters are correct.");
		}

		hr = decoder->GetFrame(0, &decodedImage);

		if (FAILED(hr))
		{
			std::string message = "Error at decoding the image: ";
			message.append(imageInfo.imagePath);

			throw new BalestraResourceException(message, "Failed at getting frame information.", "");
		}

		hr = WICFactory->CreateFormatConverter(&converter);

		if (FAILED(hr))
		{
			std::string message = "Error at decoding the image: ";
			message.append(imageInfo.imagePath);

			throw new BalestraResourceException(message, "Failed at creating the format converter.", "");
		}

		// == SCALING PROCESS

		decodedImage->GetSize(&originalW, &originalH);

		if (imageInfo.imageSize.getX() != 0)
		{
			float scalar = (imageInfo.imageSize.getX() / static_cast<float>(originalW));
			scaleFactorX = static_cast<unsigned int>(static_cast<float>(originalW)* scalar);
		}

		if (imageInfo.imageSize.getY() != 0)
		{
			float scalar = (imageInfo.imageSize.getY() / static_cast<float>(originalH));
			scaleFactorY = static_cast<unsigned int>(static_cast<float>(originalH)* scalar);
		}

		if (scaleFactorX != 1 || scaleFactorY != 1)
		{
			hr = WICFactory->CreateBitmapScaler(&scaler);

			if (FAILED(hr))
			{
				std::string message = "Error at scaling the image: ";
				message.append(imageInfo.imagePath);

				throw new BalestraResourceException(message, "Failed at creating the bitmap scaler.", "");
			}

			hr = scaler->Initialize(decodedImage, scaleFactorX, scaleFactorY, WICBitmapInterpolationModeLinear);
			
			if (FAILED(hr))
			{
				_com_error err(hr);

				std::string message = "Error at scaling the image: ";
				message.append(imageInfo.imagePath);

				throw new BalestraResourceException(message, "Failed at apply the bitmap scale.", "");
			}

			hr = converter->Initialize(
				scaler,
				GUID_WICPixelFormat32bppPBGRA,
				WICBitmapDitherTypeNone,
				NULL,
				0.f,
				WICBitmapPaletteTypeMedianCut);
		}
		else
		{
			hr = converter->Initialize(
				decodedImage,
				GUID_WICPixelFormat32bppPBGRA,
				WICBitmapDitherTypeNone,
				NULL,
				0.f,
				WICBitmapPaletteTypeMedianCut);
		}

		if (FAILED(hr))
		{
			_com_error err(hr);

			std::string message = "Error at decoding the image: ";
			message.append(imageInfo.imagePath);
	
		
			throw new BalestraResourceException(message, "Failed at converting image to compatible format.", "");
		}

		ID2D1RenderTarget* render = video->getRenderTargetView();
		ID2D1Bitmap* bitmap = nullptr;
		hr = render->CreateBitmapFromWicBitmap(converter, NULL, &bitmap);

		if (FAILED(hr))
		{
			std::string message = "Error at decoding the image: ";
			message.append(imageInfo.imagePath);

			throw new BalestraResourceException(message, "Failed at creating D2D Bitmap from converted WIC.", "");
		}

		Win32BalestraD2D1Bitmap* image = new Win32BalestraD2D1Bitmap();
		image->setPath(imageInfo.imagePath);
		image->setSize(BDoubleVector(bitmap->GetSize().width, bitmap->GetSize().height));

		Win32BalestraD2D1Bitmap* convertedImage = static_cast<Win32BalestraD2D1Bitmap*>(image);

		//SOURCE
		convertedImage->setSource(bitmap);

		return image;

	}
}

