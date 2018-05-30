#pragma once
#include "MyWindow.h"

class MovingWindowIncludedBorder : public MyWindow
{
private:
	void Move(int count, HWND window, int x, int y, int width, int height, bool redraw);
public:
	MovingWindowIncludedBorder(HINSTANCE instance, INT showCommand, LPCTSTR windowName, int x, int y, int height, int width);
	void virtual Receive(HWND sender, UINT message, WPARAM wParam, LPARAM lParam) override;
};