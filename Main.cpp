#include <iostream>
#include "Window/Window.h"

int main()
{
	//Gdiplus::GdiplusStartupInput gdiplusStartupInput; 
	//ULONG_PTR gdiplusToken;
	//Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr); 

	std::cout << "Creating Window..\n";

	Window* pWidnow = new Window();

	bool running = true;
	while (running)
	{
		if (!pWidnow->ProcessMessages())
		{
			std::cout << "Closing Window!\n";
			running = false;
		}
		Sleep(10);
	}

	delete pWidnow;

	//Gdiplus::GdiplusShutdown(gdiplusToken);
	return 0;
}