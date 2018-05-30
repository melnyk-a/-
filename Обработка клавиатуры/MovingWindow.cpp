#include "MovingWindow.h"

MovingWindow::MovingWindow(HINSTANCE instance, INT showCommand, LPCTSTR windowName, int x, int y, int width, int height) :
	MyWindow(instance, showCommand, windowName, x, y, width, height)
{
}

void MovingWindow::Receive(HWND sender, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		if (wParam == VK_LEFT)
		{
			Move(LOWORD(lParam), sender, --x, y, width, height, true);
		}
		else if (wParam == VK_RIGHT)
		{
			Move(LOWORD(lParam), sender, ++x, y, width, height, true);
		}
		else if (wParam == VK_UP)
		{
			Move(LOWORD(lParam), sender, x, --y, width, height, true);
		}
		else if (wParam == VK_DOWN)
		{
			Move(LOWORD(lParam), sender, x, ++y, width, height, true);
		}
		break;
	}
}

void MovingWindow::Move(int count, HWND window, int x, int y, int width, int height, bool redraw)
{
	int i = count;
	do
	{
		MoveWindow(window, x, y, width, height, true);
		--i;
	} while (i != 0);
}