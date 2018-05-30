#pragma once
#include <map>
#include "IColleague.h"

class Mediator
{
	static std::map<HWND, IColleague*> windows;
public:
	void AddWindow(const HWND hwnd, IColleague* myWindow);
	int GetWindowsCount();
	void RemoveWindow(HWND window);
	void Send(HWND sender, UINT message, WPARAM wParam, LPARAM lParam);
};