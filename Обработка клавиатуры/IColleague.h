#pragma once
#include <Windows.h>

class IColleague
{
public:
	virtual void Receive(HWND sender, UINT message, WPARAM wParam, LPARAM lParam) = 0;
};