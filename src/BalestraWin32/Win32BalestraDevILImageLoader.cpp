// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraDevILImageLoader.h"
#include "Win32BalestraOpenGLTexture.h"
#include "il/il.h"
#include "il/ilu.h"
#include "il/ilut.h"

namespace BalestraEngine
{
	Win32BalestraDevILImageLoader::Win32BalestraDevILImageLoader(BalestraConfiguration* configuration, BalestraEnvironmentVideo* videoEnvironment)
	{
		Win32BalestraDevILImageLoader::configuration = configuration;
		Win32BalestraDevILImageLoader::videoEnvironment = videoEnvironment;

		ilInit();
		ilEnable(IL_ORIGIN_SET);
		iluInit();
		ilutRenderer(ILUT_OPENGL);

	}

	Win32BalestraDevILImageLoader::~Win32BalestraDevILImageLoader()
	{

	}

	BalestraImage* Win32BalestraDevILImageLoader::loadImage(BImageInfo imageInfo)
	{
		if (configuration->getVideoConfiguration()->getVideoInterface() == BVIDEO_WIN32_OPENGL)
		{
			return loadImageWithDevIL(imageInfo);
		}
		else
		{
			//THROW EXCEPTION
			throw new BalestraVideoException("Error at load image using DevIL lib.", "The video interface is not compatible.", "");
		}
	}

	BalestraImage* Win32BalestraDevILImageLoader::loadImageWithDevIL(BImageInfo imageInfo)
	{
		Win32BalestraOpenGLTexture* retValue;

		GLuint textureID;
		ILuint imgID = 0;

		ilGenImages(1, &imgID);
		ilBindImage(imgID);

		wchar_t* value = Win32BalestraPlatformUtil::convertCHARtoWCHAR(imageInfo.imagePath.c_str());
		ILboolean loadState = ilLoadImage(value);

		if (loadState == IL_FALSE)
		{
			ILenum error = ilGetError();
			throw new BalestraVideoException("Error at load image using DevIL lib.", Win32BalestraPlatformUtil::convertWCHARtoCHAR(iluErrorString(error)), "");
		}

		loadState = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

		if (loadState == IL_FALSE)
		{
			ILenum error = ilGetError();
			throw new BalestraVideoException("Error at load image using DevIL lib.", Win32BalestraPlatformUtil::convertWCHARtoCHAR(iluErrorString(error)), "");
		}

		//LOADING TEXTURE (PIXEL ARRAY) TO OPENGL TEXTURE
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT), 0, GL_RGBA, GL_UNSIGNED_BYTE, ilGetData());

		glBindTexture(GL_TEXTURE_2D, NULL);

		GLenum error = glGetError();

		if (error != GL_NO_ERROR)
		{
			const char* errorString = (char*) gluErrorString(error);
			throw new BalestraVideoException("Error at texturization of an image using devIL library.", std::string(errorString), "");
		}

		//CREATING BALESTRA IMAGE OBJECT
		retValue = new Win32BalestraOpenGLTexture();
		retValue->setPath(imageInfo.imagePath);
		retValue->setSize( BDoubleVector(ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT) ));
		retValue->setTextureID(textureID);

		return retValue;
		
		
	}
}