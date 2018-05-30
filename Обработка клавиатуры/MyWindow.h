#pragma once
#include <Windows.h>
#include "Mediator.h"

class MyWindow : public IColleague
{
private:
	static TCHAR className[];
	HINSTANCE instance;
	static bool isClassCreated;
	INT showCommand;
	static WNDCLASSEX windowClass;
protected:
	int height;
	int width;
	int x;
	int y;

private:
	static void ClassInitialization(HINSTANCE instance);
	void Create(LPCTSTR windowName);
	static bool Regestration();
	static LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
public:
	MyWindow(HINSTANCE instance, INT showCommand, LPCTSTR windowName, int x, int y, int height, int width);
};