#pragma once
#include "MyWindow.h"

class MovingWindowOnTimer : public MyWindow
{
private:
	void Move(HWND window);
	void ShowMove(HWND window, int x, int y, int width, int height, bool &currentDirection, bool &nextDirection, bool condition);
public:
	MovingWindowOnTimer(HINSTANCE instance, INT showCommand, LPCTSTR windowName, int x, int y, int height, int width);
	void virtual Receive(HWND sender, UINT message, WPARAM wParam, LPARAM lParam) override;
};