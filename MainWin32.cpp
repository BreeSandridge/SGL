#include <cstdlib>
#include "Config.h"
#include "Shape.h"
#include <tchar.h>
#include <iostream>

#include "Main.h"


// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("TEST");


// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Basic Windows Application");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


Pipeline p;

//Config c = Config();




void draw(HDC hdc, Shape s);

////////////////////////////////////////////////////////////
int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow) {

	p = view(__argc, __argv);

	WNDCLASSEX wcex;


	SPI_GETWORKAREA;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// Store instance handle in our global variable
	hInst = hInstance;
	
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		p.config.currentResolutionWidth, p.config.currentResolutionHeight,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	// registers window
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



	return int(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;


	switch (message) {
	case WM_PAINT:
		// Here your application is laid out.
		// For this introduction, we just print out "Hello, Windows desktop!"
		// in the top left corner.

		// End application-specific layout section.


		hdc = BeginPaint(hWnd, &ps);
		SetGraphicsMode(hdc, GM_ADVANCED);

		// Paint the game
		//draw(hdc);
	
		for (const auto& shape : p.shapes) {
			draw(hdc, shape);
		}
		
		EndPaint(hWnd, &ps);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

void draw(HDC hdc, Shape s) {
	//Rectangle(hdc, s.left, s.top, s.right, s.bottom);
	if (s.shapeType == 0) {
		Polygon(hdc, s.get_points(), s.get_size());
	} else if (s.shapeType == rectangle) {
		RectangleShape rect = s.to_rect();
		int* data = rect.get_point_data();
		
		Rectangle(hdc, data[0], data[3], data[2], data[1]);
	} else if (s.shapeType == circle) {
		Circle c = s.to_circle();
		int* data = c.get_point_data();
		Ellipse(hdc, data[c.left], data[c.top], data[c.right], data[c.bot]);
		
	}
}

