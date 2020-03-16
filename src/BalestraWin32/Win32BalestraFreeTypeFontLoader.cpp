// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraFreeTypeFontLoader.h"
#include "Win32BalestraFreeTypeFont.h"
#include "Win32BalestraOpenGLTexture.h"
#include "BalestraFont.h"

namespace BalestraEngine
{
	Win32BalestraFreeTypeFontLoader::Win32BalestraFreeTypeFontLoader() : BalestraFontLoader()
	{
		initDevice();
	}

	Win32BalestraFreeTypeFontLoader::~Win32BalestraFreeTypeFontLoader()
	{
		cleanDevice();
	}
	
	void Win32BalestraFreeTypeFontLoader::initDevice()
	{
		FT_Error error = FT_Init_FreeType(&ftLibrary);

		if (error)
		{
			throw new BalestraVideoException("Failed at initializing freeType lib.", "Unknown error", "");
		}
	}

	B_BOOL Win32BalestraFreeTypeFontLoader::isCompatible()
	{
		return B_TRUE;
	}

	BalestraFont* Win32BalestraFreeTypeFontLoader::loadFont(BFontInfo fontInfo)
	{
		Win32BalestraFreeTypeFont* retValue = 0;
		
		//LOADING FONT 

		FT_Face face = NULL;

		FT_Error error = FT_New_Face(ftLibrary, fontInfo.fontPath.c_str(), 0, &face);

		if (error == FT_Err_Unknown_File_Format)
		{
			throw new BalestraVideoException("Failed at load font file on FreeType lib.", "Unknown error", "");
		}
		else if (error)
		{
			throw new BalestraVideoException("Failed at load font file on FreeType lib.", "Unknown error", "");
		}

		//CONFIG FONT
		error = FT_Set_Char_Size(face, 16 << 6, 16 << 6, 96, 96) != 0;

		if (error)
		{
			throw new BalestraVideoException("Failed at config pixel size for a font on FreeType lib.", "Unknown error", "");
		}

		retValue = new Win32BalestraFreeTypeFont();

		for (int count = ' '; count <= '~'; ++count)
		{
			FT_Glyph glyph;

			uint32_t index = FT_Get_Char_Index(face, count);
			
			if (index == 0)
			{
				continue;
			}

			FT_Load_Glyph(face, index, FT_LOAD_RENDER);
			FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

			FT_Get_Glyph(face->glyph, &glyph);

			FT_GlyphSlot slot = face->glyph;
			FT_Bitmap& bitmap = slot->bitmap;

			uint32_t w = bitmap.width;
			uint32_t h = bitmap.rows;

			uint32_t texture = 0;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
				
			unsigned char* data = new unsigned char[w * h];
			memset(data, NULL, w * h *  sizeof(unsigned char));
			memcpy(data, bitmap.buffer, sizeof(unsigned char) * w * h);

			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, 0, GL_RED, w, h, GL_UNSIGNED_BYTE, data);

			glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

			delete[] data;
			FT_Done_Glyph(glyph);

			Win32BalestraOpenGLTexture textureObj = Win32BalestraOpenGLTexture();
			textureObj.setTextureID(texture);
			textureObj.setSize(BDoubleVector(w, h));

			BalestraGlyph b_glyph;
			b_glyph.texture = textureObj;
			b_glyph.width = w;
			b_glyph.height = h;
			b_glyph.advancement = slot->advance.x >> 6;
			b_glyph.heightOffset = slot->metrics.horiBearingX >> 6;

			retValue->setCharAt(b_glyph, count);
		}

		FT_Done_Face(face);

		retValue->setFilePath(fontInfo.fontPath);

		return retValue;
	}

	void Win32BalestraFreeTypeFontLoader::cleanDevice()
	{
		delete(ftLibrary);
	}

}