// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraOpenGLRenderGear.h"
#include "Win32BalestraOpenGLEnvironment.h"
#include "Win32BalestraOpenGLTexture.h"
#include "Win32BalestraFreeTypeFont.h"

#include "ft2build.h"
#include FT_FREETYPE_H


namespace BalestraEngine
{

	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraOpenGLRenderGear::Win32BalestraOpenGLRenderGear(Win32BalestraOpenGLEnvironment* videoEnv) : BalestraRenderGear(videoEnv)
	{
		win32OpenGLEnvironment = videoEnv;
	}

	Win32BalestraOpenGLRenderGear::~Win32BalestraOpenGLRenderGear()
	{

	}

	void Win32BalestraOpenGLRenderGear::clearRenderTarget(B32ARGBColorFloat* color)
	{
		videoEnv->cleanRenderTarget(color);
	}

	void Win32BalestraOpenGLRenderGear::startDraw()
	{

	}

	void Win32BalestraOpenGLRenderGear::draw2DRect(Balestra2DRect* rect)
	{
		BRect objRect = rect->getRect();

		// == RETRIEVING INFORMATION
		BalestraCamera* camera = win32OpenGLEnvironment->getCamera();

		// == COLOR
		glColor4d(rect->getColor()->getRed(), rect->getColor()->getGreen(), rect->getColor()->getBlue(), rect->getColor()->getAlpha());

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glScaled(rect->getScale()->getX(), rect->getScale()->getY(), 0);

		// == TRANSTALATION
		glTranslated(rect->getPosition()->getX(), rect->getPosition()->getY(), 0);

		// == ROTATION
		glRotatef(rect->getRotationAngle()->getAngle(), 0.0f, 0.0f, 1.0f);

		//SET POINT TO ORIGIN
		glTranslated(-rect->getOrigin()->getX(), -rect->getOrigin()->getY(), 0);

		// == SCALE

		// == DRAW

		glBegin(GL_TRIANGLE_STRIP);

		glVertex2d(0, rect->getSize()->getY());
		glVertex2d(0, 0);
		glVertex2d(rect->getSize()->getX(), 0);
		glVertex2d(0, rect->getSize()->getY());
		glVertex2d(rect->getSize()->getX(), rect->getSize()->getY());
		glVertex2d(rect->getSize()->getX(), 0);

		glEnd();
	}

	void Win32BalestraOpenGLRenderGear::draw2DText(Balestra2DText* text2D)
	{
		// == RETRIEVING INFORMATION
		BalestraCamera* camera = win32OpenGLEnvironment->getCamera();
		Win32BalestraFreeTypeFont* font = static_cast<Win32BalestraFreeTypeFont *>(text2D->getFont());

		// == CONFIG
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// == TEXTURE
		Win32BalestraOpenGLTexture texture = static_cast<Win32BalestraOpenGLTexture>(font->getCharAt(72).texture);

		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();

		glBindTexture(GL_TEXTURE_2D, texture.getTextureID());

		// == COLOR
		//glColor4d(sprite->getColor()->getRed(), sprite->getColor()->getGreen(), sprite->getColor()->getBlue(), sprite->getColor()->getAlpha());
		glColor4d(1.0f, 1.0f, 1.0f, 1.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// == TRANSTALATION
		glTranslated(text2D->getPosition()->getX() - camera->getX(), text2D->getPosition()->getY() - camera->getY(), 0);

		// == ROTATION
		glRotatef(text2D->getRotationAngle()->getAngle(), 0.0f, 0.0f, 1.0f);

		// == SCALE
		glScalef(1.0f, 1.0f, 0);

		//FLIP

		if (text2D->getFlipX() == B_TRUE)
		{
			glScaled(-text2D->getScale()->getX(), text2D->getScale()->getY(), 0);
		}

		glScaled(text2D->getScale()->getX(), text2D->getScale()->getY(), 0);

		//SET POINT TO ORIGIN
		glTranslated(-text2D->getOrigin()->getX(), -text2D->getOrigin()->getY(), 0);

		// == DRAW

		glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 1.0f); glVertex2f(0.f, 0.f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(texture.getSize().getX(), 0.f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(texture.getSize().getX(), texture.getSize().getY());
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0.f, texture.getSize().getY());

		glEnd();
	}

	void Win32BalestraOpenGLRenderGear::draw2DSprite(Balestra2DSprite* sprite)
	{
		// == RETRIEVING INFORMATION
		BalestraCamera* camera = win32OpenGLEnvironment->getCamera();

		// == CONFIG
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// == TEXTURE
		Win32BalestraOpenGLTexture* texture = static_cast<Win32BalestraOpenGLTexture*>(sprite->getAnimationController()->getCurrentImage());

		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();

		glBindTexture(GL_TEXTURE_2D, texture->getTextureID());

		// == COLOR
		//glColor4d(sprite->getColor()->getRed(), sprite->getColor()->getGreen(), sprite->getColor()->getBlue(), sprite->getColor()->getAlpha());
		glColor4d(1.0f, 1.0f, 1.0f, 1.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// == TRANSTALATION
		glTranslated(sprite->getPosition()->getX() - camera->getX(), sprite->getPosition()->getY() - camera->getY(), 0);

		// == ROTATION
		glRotatef(sprite->getRotationAngle()->getAngle(), 0.0f, 0.0f, 1.0f);

		// == SCALE
		glScalef(1.0f, 1.0f, 0);

		//FLIP

		if (sprite->getFlipX() == B_TRUE)
		{
			glScaled(-sprite->getScale()->getX(), sprite->getScale()->getY(), 0);
		}

		glScaled(sprite->getScale()->getX(), sprite->getScale()->getY(), 0);

		//SET POINT TO ORIGIN
		glTranslated(-sprite->getOrigin()->getX(), -sprite->getOrigin()->getY(), 0);

		// == DRAW

		glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 1.0f); glVertex2f(0.f, 0.f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(sprite->getSize()->getX(), 0.f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(sprite->getSize()->getX(), sprite->getSize()->getY());
		glTexCoord2f(0.0f, 0.0f); glVertex2f(0.f, sprite->getSize()->getY());

		glEnd();

		// == FINALIZATION
	}

	void Win32BalestraOpenGLRenderGear::stopDraw()
	{
		SwapBuffers(win32OpenGLEnvironment->getGLContext());
	}

}