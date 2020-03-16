// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraEnvironmentResource.h"
#include "Win32BalestraWICImageLoader.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraXAudio2SoundLoader.h"
#include "Win32BalestraConfigurationPlatform.h"
#include "Win32BalestraDevILImageLoader.h"
#include "Win32BalestraFreeTypeFontLoader.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraEnvironmentResource::Win32BalestraEnvironmentResource(BalestraConfiguration* configuration, BalestraEnvironmentVideo* videoEnvironment) : BalestraEnvironmentResource(configuration, videoEnvironment)
	{
		Win32BalestraEnvironmentResource::configuration = configuration;
	}

	B_BOOL Win32BalestraEnvironmentResource::isCompatible()
	{
		// = IMAGE LOADER =======================

		switch (configuration->getDecoderConfiguration()->getImageDecoderInterface())
		{
			case BIMAGEDECODER_MS_WIC:
				return checkWICCompatibility();
				break;

			case BIMAGEDECODER_DEVIL:
				return B_TRUE;
				break;

			default:
				throw new BalestraResourceException("Error at checking system compatibility for the image codec.", "The image codec is invalid", "Check if the current image decoder is valid.");
				break;
		}

		// = SOUND LOADER =======================
	}

	B_BOOL Win32BalestraEnvironmentResource::checkWICCompatibility()
	{
		int osCode = static_cast<Win32BalestraConfiguration*>(configuration)->getPlatformConfiguration()->getOperationalSystem();

		if (osCode != BPLATFORM_OS_XP_SP2 && osCode != BPLATFORM_OS_XP_SP3 && osCode != BPLATFORM_OS_VISTA && osCode != BPLATFORM_OS_VISTA_SP1 && osCode != BPLATFORM_OS_VISTA_SP2 && osCode != BPLATFORM_OS_WIN7 && osCode != BPLATFORM_OS_WIN7_SP1 && osCode != BPLATFORM_OS_WIN8 && osCode != BPLATFORM_OS_WIN8_1)
		{
			std::string sysMsg = "The current operational system (";
			sysMsg.append(Win32BalestraPlatformUtil::getOsSystemName(osCode));
			sysMsg.append(") is incompatible with the current Image Decoder (Windows Imaging Components).");

			throw new BalestraResourceException("Error at iniatilizing the image decoder component.", sysMsg, "");
			return B_FALSE;
		}
		else
		{
			return B_TRUE;
		}
	}

	void Win32BalestraEnvironmentResource::initDevice()
	{
		Win32BalestraEnvironmentResource::isCompatible();
	}

	BalestraImageLoader* Win32BalestraEnvironmentResource::createImageLoader()
	{
		// CREATES AN IMAGE LOADER BASED ON THE API'S SELECTED BY USER

		switch (configuration->getVideoConfiguration()->getVideoInterface())
		{
			case BVIDEO_WIN32_DIRECT2D_1:

				switch (configuration->getDecoderConfiguration()->getImageDecoderInterface())
				{
					case BIMAGEDECODER_MS_WIC:
						return new Win32BalestraWICImageLoader(configuration, videoEnvironment);
						break;

					default:
						throw new BalestraResourceException("Error at creating an image loader.", "Unsupported/Unknown image decoder to the current video interface", "Choice a new image decoder interface compatible with the selected video interface.");
						break;
				}

				break;
			
			case BVIDEO_WIN32_OPENGL:

				switch (configuration->getDecoderConfiguration()->getImageDecoderInterface())
				{
					case BIMAGEDECODER_DEVIL:
						return new Win32BalestraDevILImageLoader(configuration, videoEnvironment);

					default:
						throw new BalestraResourceException("Error at creating an image loader.", "Unsupported/Unknown image decoder to the current video interface", "Choice a new image decoder interface compatible with the selected video interface.");
						break;
				}

				break;

			default:
				throw new BalestraResourceException("Error at creating an image loader.", "The video interface is unknown", "Check if the current video interface is valid.");
				break;
		}
	}

	BalestraSoundLoader* Win32BalestraEnvironmentResource::createSoundLoader()
	{
		return new Win32BalestraXAudio2SoundLoader();
	}

	BalestraFontLoader* Win32BalestraEnvironmentResource::createFontLoader()
	{
		switch (configuration->getVideoConfiguration()->getVideoInterface())
		{

		case BVIDEO_WIN32_DIRECT2D_1:

			return 0;
			break;

		case BVIDEO_WIN32_OPENGL:

			return new Win32BalestraFreeTypeFontLoader();
			break;

		default:
			throw new BalestraResourceException("Error at creating an image loader.", "The video interface is unknown", "Check if the current video interface is valid.");
			break;
		}
	}

	void Win32BalestraEnvironmentResource::cleanDevice()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	Win32BalestraConfiguration* Win32BalestraEnvironmentResource::getW32Configuration()
	{
		return static_cast<Win32BalestraConfiguration*>(configuration);
	}
}