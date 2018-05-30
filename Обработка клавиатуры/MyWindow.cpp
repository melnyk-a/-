#include <vector>
#include "MyWindow.h"
#include "Mediator.h"

bool MyWindow::isClassCreated = false;
TCHAR MyWindow::className[] = TEXT("My window");
WNDCLASSEX MyWindow::windowClass = {};

MyWindow::MyWindow(HINSTANCE instance, INT showCommand, LPCTSTR windowName, int x, int y, int height, int width) :
	instance(instance),
	showCommand(showCommand),
	x(x),
	y(y),
	height(height),
	width(width)
{
	if (!isClassCreated)
	{
		ClassInitialization(instance);
		Regestration();
		isClassCreated = true;
	}
	Create(windowName);
}

void  MyWindow::ClassInitialization(HINSTANCE instance)
{
	windowClass.cbClsExtra = 0;
	windowClass.cbSize = sizeof(windowClass);
	windowClass.cbWndExtra = 0;
	windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	windowClass.hInstance = instance;
	windowClass.lpfnWndProc = WindowProcedure;
	windowClass.lpszClassName = className;
	windowClass.lpszMenuName = nullptr;
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
}

LRESULT CALLBACK MyWindow::WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;

	static Mediator mediator;

	switch (message)
	{
	case WM_CREATE:
	{
		CREATESTRUCT*  windowStruct = (CREATESTRUCT*)lParam;
		IColleague* colleague = static_cast<IColleague*>(windowStruct->lpCreateParams);
		mediator.AddWindow(window, colleague);
		break;
	}
	case WM_KEYDOWN:
		mediator.Send(window, message, wParam, lParam);
		break;
	case WM_TIMER:
		mediator.Send(window, message, wParam, lParam);
		break;
	case WM_DESTROY:
		if (mediator.GetWindowsCount() == 1)
		{
			PostQuitMessage(0);
		}
		else
		{
			mediator.RemoveWindow(window);
		}
		break;
	default:
		result = DefWindowProc(window, message, wParam, lParam);
		break;
	}
	return result;
}

bool MyWindow::Regestration()
{
	return RegisterClassEx(&windowClass);
}

void MyWindow::Create(LPCTSTR windowName)
{
	HWND window = CreateWindowEx(0UL, className, windowName, WS_OVERLAPPEDWINDOW, x, y, width, height, nullptr, nullptr, instance, this);
	ShowWindow(window, showCommand);
	UpdateWindow(window);
}