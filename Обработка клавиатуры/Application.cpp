#include "Application.h"
#include "MyWindow.h"
#include "MovingWindow.h"
#include "MovingWindowIncludedBorder.h"
#include "MovingWindowOnTimer.h"

Application::Application(HINSTANCE instance, INT showCommand)
{
	LPCTSTR windowName = TEXT("Moving Window");
	MyWindow* window = new MovingWindow(instance, showCommand, windowName, 200, 0, 300, 300);
	windows.push_back(window);

	windowName = TEXT("Moving Window Included Border");
	window = new MovingWindowIncludedBorder(instance, showCommand, windowName, 300, 100, 300, 300);
	windows.push_back(window);

	windowName = TEXT("Moving Window On timer");
	window = new MovingWindowOnTimer(instance, showCommand, windowName, 500, 200, 300, 300);
	windows.push_back(window);
}

void Application::Run()
{
	MSG message = {};

	while (GetMessage(&message, nullptr, 0U, 0U))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	exitCode = message.wParam;
}

INT Application::GetExitCode()
{
	return exitCode;
}

Application::~Application()
{
	for (int i = 0; i < windows.size(); i++)
	{
		delete windows[i];
	}
}