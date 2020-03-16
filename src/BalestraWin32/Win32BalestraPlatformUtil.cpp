
// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraPlatformUtil.h"

namespace BalestraEngine
{
	wchar_t* Win32BalestraPlatformUtil::convertCHARtoWCHAR(const char* value)
	{
		size_t newSize = strlen(value) + 1;
		wchar_t* wcString = new wchar_t[newSize];
		size_t convertedChars = 0;

		mbstowcs_s(&convertedChars, wcString, newSize, value, _TRUNCATE);

		return wcString;
	}

	char* Win32BalestraPlatformUtil::convertWCHARtoCHAR(const wchar_t* value)
	{
		size_t   i;
		char* retValue = (char *)malloc(100);

		// Conversion
		wcstombs_s(&i, retValue, (size_t)100,
			value, (size_t)100);

		return retValue;
	}

	std::string Win32BalestraPlatformUtil::getOsSystemName(int osCode)
	{
		switch (osCode)
		{
		case BPLATFORM_OS_XP:
			return "Microsoft Windows XP";
			break;

		case BPLATFORM_OS_XP_SP1:
			return "Microsoft Windows XP - Service Pack 1";
			break;

		case BPLATFORM_OS_XP_SP2:
			return "Microsoft Windows XP - Service Pack 2";
			break;

		case BPLATFORM_OS_XP_SP3:
			return "Microsoft Windows XP - Service Pack 3";
			break;

		case BPLATFORM_OS_VISTA:
			return "Microsoft Windows Vista";
			break;

		case BPLATFORM_OS_VISTA_SP1:
			return "Microsoft Windows Vista - Service Pack 1";
			break;

		case BPLATFORM_OS_VISTA_SP2:
			return "Microsoft Windows Vista - Service Pack 2";
			break;

		case BPLATFORM_OS_WIN7:
			return "Microsoft Windows 7";
			break;

		case BPLATFORM_OS_WIN7_SP1:
			return "Microsoft Windows 7 - Service Pack 1";
			break;

		case BPLATFORM_OS_WIN8:
			return "Microsoft Windows 8";
			break;

		case BPLATFORM_OS_WIN8_1:
			return "Microsoft Windows 8.1";
			break;

		default:
			return "Unknown";
			break;
		}
	}
}
