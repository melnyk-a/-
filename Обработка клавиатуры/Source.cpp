#include "Application.h"
#include <tchar.h>

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT showCommand)
{
	Application application(instance, showCommand);
	application.Run();

	return application.GetExitCode();
}