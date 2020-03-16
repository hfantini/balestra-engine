// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraUserCommunication.h"
#include "Win32BalestraConfigurationPlatform.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraUserCommunication::Win32BalestraUserCommunication()
	{

	}

	Win32BalestraUserCommunication::Win32BalestraUserCommunication(Win32BalestraConfiguration* config)
	{
		Win32BalestraUserCommunication::configuration = config;
	}

	Win32BalestraUserCommunication::~Win32BalestraUserCommunication()
	{

	}

	void Win32BalestraUserCommunication::consoleErrorMessage(std::string message)
	{
		message.append("\n");
		OutputDebugStringA(message.c_str());
	}

	void Win32BalestraUserCommunication::consoleWarningMessage(std::string message)
	{
		message.append("\n");
		OutputDebugStringA(message.c_str());
	}

	void Win32BalestraUserCommunication::consoleInfoMessage(std::string message)
	{
		message.append("\n");
		OutputDebugStringA(message.c_str());
	}

	void Win32BalestraUserCommunication::consoleExceptionMessage(BalestraException* ex)
	{
		std::string exMessage = "The application threw an exception and cannot continue. \n\nMessage: \n";
		exMessage.append(ex->getMessage());
		exMessage.append("\n\nSystemMessage: \n");
		exMessage.append(ex->getSystemMessage());
		exMessage.append("\n\nSolution: \n");
		exMessage.append(ex->getSolution());

		std::cout << exMessage;
		OutputDebugStringA(exMessage.c_str());
	}

	void Win32BalestraUserCommunication::platformErrorMessage(std::string title, std::string message)
	{
		MessageBoxA(configuration->getPlatformConfiguration()->getMainWindowHandle(), message.c_str(), title.c_str(), MB_ICONERROR | MB_OK);
	}

	void Win32BalestraUserCommunication::platformWarningMessage(std::string title, std::string message)
	{
		MessageBoxA(configuration->getPlatformConfiguration()->getMainWindowHandle(), message.c_str(), title.c_str(), MB_ICONWARNING | MB_OK);
	}

	void Win32BalestraUserCommunication::platformInfoMessage(std::string title, std::string message)
	{
		MessageBoxA(configuration->getPlatformConfiguration()->getMainWindowHandle(), message.c_str(), title.c_str(), MB_ICONINFORMATION | MB_OK);
	}

	void Win32BalestraUserCommunication::platformExceptionMessage(BalestraException* ex)
	{
		std::string exMessage = "The application threw an exception and cannot continue. \n\nMessage: \n";
		exMessage.append(ex->getMessage());
		exMessage.append("\n\nSystemMessage: \n");
		exMessage.append(ex->getSystemMessage());
		exMessage.append("\n\nSolution: \n");
		exMessage.append(ex->getSolution());

		if (configuration)
		{
			MessageBoxA(configuration->getPlatformConfiguration()->getMainWindowHandle(), exMessage.c_str(), "Exception", MB_ICONERROR | MB_OK);
		}
		else
		{
			MessageBoxA(NULL, exMessage.c_str(), "Exception", MB_ICONERROR | MB_OK);
		}
	}
}