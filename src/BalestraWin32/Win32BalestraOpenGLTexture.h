// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"

#ifndef _INC_BALESTRA_OPENGL_TEXTURE

#define _INC_BALESTRA_OPENGL_TEXTURE

namespace BalestraEngine
{
	class Win32BalestraOpenGLTexture : public BalestraImage
	{
	public:

		// == METHODS ======================================
		Win32BalestraOpenGLTexture();
		~Win32BalestraOpenGLTexture();

		void unloadResource() override;

		// == GETTERS AND SETTERS ==========================
		void setTextureID(GLuint value);
		GLuint getTextureID();

	private:

	protected:

		GLuint textureID;

		// == VAR & CONST ===================================

	};
}

#endif