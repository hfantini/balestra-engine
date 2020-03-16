// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraD2D1RenderGear.h"
#include "Win32BalestraD2D1Environment.h"
#include "Win32BalestraD2D1Bitmap.h"

namespace BalestraEngine
{

	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraD2D1RenderGear::Win32BalestraD2D1RenderGear(Win32BalestraD2D1Environment* videoEnv) : BalestraRenderGear(videoEnv)
	{

	}

	Win32BalestraD2D1RenderGear::~Win32BalestraD2D1RenderGear()
	{

	}

	void Win32BalestraD2D1RenderGear::clearRenderTarget(B32ARGBColorFloat* color)
	{
		videoEnv->cleanRenderTarget(color);
	}

	void Win32BalestraD2D1RenderGear::startDraw()
	{
		Win32BalestraD2D1Environment* D2DVideo = dynamic_cast<Win32BalestraD2D1Environment*>(videoEnv);
		D2DVideo->getRenderTargetView()->BeginDraw();
	}

	void Win32BalestraD2D1RenderGear::draw2DRect(Balestra2DRect* rect)
	{
		Win32BalestraD2D1Environment* D2DVideo = dynamic_cast<Win32BalestraD2D1Environment*>(videoEnv);

		D2DVideo->getDefaultSolidBrush()->SetColor({ rect->getColor()->getRed(), rect->getColor()->getGreen(), rect->getColor()->getBlue(), rect->getColor()->getAlpha() });

		float X = 0;
		float Y = 0;
		float W = rect->getSize()->getX();
		float H = rect->getSize()->getY();

		D2D1_RECT_F dxRect = D2D1::RectF(X, Y, W, H);

		// == CALCULING TRANSFORMATIONS
		// ================================================

		// == ROTATION ====================================

		// == SCALE =======================================

		// == SKEW ========================================

		// == TRANSLATION ====================================

		D2D1::Matrix3x2F translateM = D2D1::Matrix3x2F::Identity();
		translateM = D2D1::Matrix3x2F::Translation((rect->getPosition()->getX() - rect->getOrigin()->getX()) - D2DVideo->getCamera()->getX(), (rect->getPosition()->getY() - rect->getOrigin()->getY()) - D2DVideo->getCamera()->getY());

		D2DVideo->getRenderTargetView()->SetTransform(translateM);
		D2DVideo->getRenderTargetView()->FillRectangle(&dxRect, D2DVideo->getDefaultSolidBrush());
	}

	void Win32BalestraD2D1RenderGear::draw2DText(Balestra2DText* text2D)
	{
		/*HRESULT hr;
		IDWriteTextFormat* textFormat;
		Win32BalestraD2D1Environment* D2DVideo = dynamic_cast<Win32BalestraD2D1Environment*>(videoEnv);
		
		D2DVideo->getDefaultSolidBrush()->SetColor(D2D1::ColorF(text2D->getColor()->getRed(), text2D->getColor()->getGreen(), text2D->getColor()->getBlue(), text2D->getColor()->getAlpha()));

		wchar_t* fontName = Win32BalestraPlatformUtil::convertCHARtoWCHAR(text2D->getFontName().c_str());
		wchar_t* text = Win32BalestraPlatformUtil::convertCHARtoWCHAR(text2D->getText().c_str());

		hr = D2DVideo->getWriteFactory()->CreateTextFormat(
			fontName,
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			text2D->getFontSize(),
			L"",
			&textFormat);

		if (FAILED(hr))
		{
			throw new BalestraVideoException("Error at create the DirectWrite Text Format", "", "");
		}

		// == CREATING RECT ===============================

		float X = 0;
		float Y = 0;
		float W = text2D->getSize()->getX();
		float H = text2D->getSize()->getY();

		D2D1_RECT_F dxRect = D2D1::RectF(X, Y, W, H);

		// == CALCULING TRANSFORMATIONS ===================

		// -- TRANSLATION ---------------------------------

		D2D1::Matrix3x2F translationMatrix = D2D1::Matrix3x2F::Identity();
		translationMatrix = D2D1::Matrix3x2F::Translation(text2D->getPosition()->getX() - text2D->getOrigin()->getX(), text2D->getPosition()->getY() - text2D->getOrigin()->getY());

		// == DRAW PROCESS ================================

		D2DVideo->getRenderTargetView()->SetTransform(translationMatrix);

		D2DVideo->getRenderTargetView()->DrawTextW(
			text,
			wcslen(text),
			textFormat,
			dxRect,
			D2DVideo->getDefaultSolidBrush()
			);

		if (FAILED(hr))
		{
			throw new BalestraVideoException("Error at draw text with DirectWrite", "", "");
		}

		delete fontName;
		delete text;*/
	}

	void Win32BalestraD2D1RenderGear::draw2DSprite(Balestra2DSprite* sprite)
	{
		Win32BalestraD2D1Bitmap* bitmap = static_cast<Win32BalestraD2D1Bitmap*>(sprite->getAnimationController()->getCurrentImage());

		if (bitmap)
		{
			Win32BalestraD2D1Environment* D2DVideo = dynamic_cast<Win32BalestraD2D1Environment*>(videoEnv);

			// -- CREATING RECT ---------------

			float X = 0;
			float Y = 0;
			float W = sprite->getSize()->getX();
			float H = sprite->getSize()->getY();

			D2D1_RECT_F dxRect = D2D1::RectF(X, Y, W, H);
			D2D1_RECT_F dxRectSource = D2D1::RectF(0, 0, 0, 0);

			// == CALCULING TRANSFORMATIONS
			// ================================================

			// == ROTATION ====================================

			D2D1::Matrix3x2F rotateM = D2D1::Matrix3x2F::Identity();
			rotateM = D2D1::Matrix3x2F::Rotation(sprite->getRotationAngle()->getAngle(), D2D1::Point2F(sprite->getOrigin()->getX(), sprite->getOrigin()->getY()));

			// == SCALE =======================================

			D2D1::Matrix3x2F scaleM = D2D1::Matrix3x2F::Identity();

			// -- FLIP ------------------------

			float flipXFactor = 1.0f;
			float flipYFactor = 1.0f;
			
			if (sprite->getFlipX() == B_TRUE)
			{
				flipXFactor *= -1;
			}
			else if (sprite->getFlipY() == B_TRUE)
			{
				flipYFactor *= -1;
			}

			scaleM = D2D1::Matrix3x2F::Scale(flipXFactor, flipYFactor, D2D1::Point2F(sprite->getOrigin()->getX(), sprite->getOrigin()->getY()));

			// -- TRANSLATING -----------------
			D2D1::Matrix3x2F translateM = D2D1::Matrix3x2F::Identity();
			translateM = D2D1::Matrix3x2F::Translation((sprite->getPosition()->getX() - sprite->getOrigin()->getX()) - D2DVideo->getCamera()->getX(), (sprite->getPosition()->getY() - sprite->getOrigin()->getY()) - D2DVideo->getCamera()->getY());

			// == DRAW PROCESS ================================

			D2DVideo->getRenderTargetView()->SetTransform(rotateM * scaleM * translateM);
			D2DVideo->getRenderTargetView()->DrawBitmap(bitmap->getSource(), dxRect, sprite->getColor()->getAlpha(), D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, NULL);
		}
	}

	void Win32BalestraD2D1RenderGear::stopDraw()
	{
		Win32BalestraD2D1Environment* D2DVideo = dynamic_cast<Win32BalestraD2D1Environment*>(videoEnv);
		D2DVideo->getRenderTargetView()->EndDraw();
	}

}