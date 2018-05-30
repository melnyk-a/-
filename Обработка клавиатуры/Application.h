#pragma once
#include <Windows.h>
#include <vector>
#include "MyWindow.h"

class  Application
{
public:
	Application(HINSTANCE instance, INT showCommand);
	INT GetExitCode();
	void Run();
	~Application();
private:
	INT exitCode = 0;
	std::vector<MyWindow*> windows;
};