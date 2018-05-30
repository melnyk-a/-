#include "Mediator.h"

std::map<HWND, IColleague*> Mediator::windows;

void Mediator::AddWindow(const HWND hwnd, IColleague* myWindow)
{
	std::pair<const HWND, IColleague*> windowPair = { hwnd,  myWindow };
	windows.insert(windowPair);
}

void Mediator::Send(HWND sender, UINT message, WPARAM wParam, LPARAM lParam)
{
	std::map<HWND, IColleague*>::iterator it;
	it = windows.find(sender);
	it->second->Receive(sender, message, wParam, lParam);
}

void Mediator::RemoveWindow(HWND window)
{
	windows.erase(window);
}

int Mediator::GetWindowsCount()
{
	return windows.size();
}