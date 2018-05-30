#include "MovingWindowIncludedBorder.h"

MovingWindowIncludedBorder::MovingWindowIncludedBorder(HINSTANCE instance, INT showCommand, LPCTSTR windowName, int x, int y, int width, int height) :
	MyWindow(instance, showCommand, windowName, x, y, width, height)
{
}

void MovingWindowIncludedBorder::Receive(HWND sender, UINT message, WPARAM wParam, LPARAM lParam)
{
	const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	switch (message)
	{

	case WM_KEYDOWN:
		if (wParam == VK_LEFT)
		{
			if (x > 0)
			{
				Move(LOWORD(lParam), sender, --x, y, width, height, true);
			}
		}
		else if (wParam == VK_RIGHT)
		{
			if (x + width < screenWidth)
			{
				Move(LOWORD(lParam), sender, ++x, y, width, height, true);
			}
		}
		else if (wParam == VK_UP)
		{
			if (y > 0)
			{
				Move(LOWORD(lParam), sender, x, --y, width, height, true);
			}
		}
		else if (wParam == VK_DOWN)
		{
			if (y + height < screenHeight)
			{
				Move(LOWORD(lParam), sender, x, ++y, width, height, true);
			}
		}
		break;
	}
}

void MovingWindowIncludedBorder::Move(int count, HWND window, int x, int y, int width, int height, bool redraw)
{
	int i = count;
	do
	{
		MoveWindow(window, x, y, width, height, true);
		--i;
	} while (i != 0);
}