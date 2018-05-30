#include "MovingWindowOnTimer.h"

MovingWindowOnTimer::MovingWindowOnTimer(HINSTANCE instance, INT showCommand, LPCTSTR windowName, int x, int y, int height, int width) :
	MyWindow(instance, showCommand, windowName, x, y, height, width)
{
}

void MovingWindowOnTimer::Receive(HWND sender, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
		{
			x = 0;
			y = 0;
			SetTimer(sender, 1U, 1U, nullptr);
			MoveWindow(sender, 0, 0, width, height, true);
		}
		else if (wParam = VK_ESCAPE)
		{
			KillTimer(sender, 1U);
		}
		break;
	case WM_TIMER:
		Move(sender);
		break;
	}
}

void MovingWindowOnTimer::Move(HWND window)
{
	static bool right = false;
	static bool down = false;
	static bool left = false;
	static bool up = false;

	if (x == 0 && y == 0)
	{
		right = true;
		down = false;
		left = false;
		up = false;
	}

	const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (right)
	{
		ShowMove(window, ++x, y, width, height, right, down, x + width > screenWidth);
	}
	if (down)
	{
		ShowMove(window, x, ++y, width, height, down, left, y + height > screenHeight);
	}
	if (left)
	{
		ShowMove(window, --x, y, width, height, left, up, x == 0);
	}
	if (up)
	{
		ShowMove(window, x, --y, width, height, up, right, y == 0);
	}
}

void MovingWindowOnTimer::ShowMove(HWND window, int x, int y, int height, int width, bool &currentDirection, bool &nextDirection, bool condition)
{
	MoveWindow(window, x, y, height, width, true);
	if (condition)
	{
		currentDirection = false;
		nextDirection = true;
	}
}