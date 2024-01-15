#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (uMsg)
	{
	//case WM_PAINT:
	//	hdc = BeginPaint(hwnd, &ps);
	//	DrawP->K2_Box(hdc);
	//	EndPaint(hwnd, &ps);
	//	return 0;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



Window::Window() 
	: m_hInstance(GetModuleHandle(nullptr))
{
	std::cout << "Creating Window Class..\n";
	const wchar_t* class_name = L"Cool game";

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = class_name;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);
	std::cout << "Registering Window...\n";

	DWORD style = WS_CAPTION | WS_MAXIMIZEBOX | WS_SYSMENU;

	int width = 640;
	int height = 480;

	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	m_hwnd = CreateWindowEx(
		0,
		class_name,
		L"Cool game",
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hInstance,
		NULL
	);

	std::cout << "hwnd and window rect made...\n";


	ShowWindow(m_hwnd, SW_SHOW);
}

Window::~Window()
{
	const wchar_t* class_name = L"Cool game";


	std::cout << "UnRegistering Window...\n";
	UnregisterClass(class_name, m_hInstance);
}

bool Window::ProcessMessages()
{
	MSG message = {};

	while (PeekMessage(&message, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (message.message == WM_QUIT)
		{
			std::cout << "Quiting message proc.\n";

			return false;
		}

		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return true;
}