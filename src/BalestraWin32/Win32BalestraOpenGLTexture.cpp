// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================
#include "Win32BalestraOpenGLTexture.h"

namespace BalestraEngine
{

	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraOpenGLTexture::Win32BalestraOpenGLTexture()
	{
		Win32BalestraOpenGLTexture::textureID = 0;
	}

	Win32BalestraOpenGLTexture::~Win32BalestraOpenGLTexture()
	{
		Win32BalestraOpenGLTexture::unloadResource();
	}

	void Win32BalestraOpenGLTexture::unloadResource()
	{
		if (Win32BalestraOpenGLTexture::textureID != 0)
		{
			glDeleteTextures(1, &textureID);
		}
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	GLuint Win32BalestraOpenGLTexture::getTextureID()
	{
		return Win32BalestraOpenGLTexture::textureID;
	}

	void Win32BalestraOpenGLTexture::setTextureID(GLuint value)
	{
		Win32BalestraOpenGLTexture::textureID = value;
	}

}