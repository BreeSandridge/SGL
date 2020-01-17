// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c
/*
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("TEST");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Basic Windows Application");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void draw(HDC hdc);
void drawLine(HDC hdc, int start_x, int start_y, int end_x, int end_y);
void drawText(HDC hdc, int x, int y, TCHAR str[]);
void drawRectangle(HDC hdc, int left, int top, int right, int bot);
void drawEllipses(HDC hdc, int xLeft, int yTop, int xRight, int yBottom);
void drawCircle(HDC hdc, int x, int y, int radius);
void drawPolygon(HDC hdc, POINT* p, int sides);

// 2 vars to store width and height
int currentResolutionWidth = 200;
int currentResolutionHeight = 100;



// main function
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
) {

	// SystemParametersInfo() gets the work area and stores the value in the rectangle
	RECT rectWork = { 0 };
	if (SystemParametersInfo(SPI_GETWORKAREA, 0, &rectWork, 0)) {
		//gets the current res
		currentResolutionWidth = rectWork.right - rectWork.left;
		currentResolutionHeight = rectWork.bottom - rectWork.top;
	}



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

	


	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		currentResolutionWidth, currentResolutionHeight,
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

	return (int)msg.wParam;
}


//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
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

		// Paint the game
		draw(hdc);

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

void draw(HDC hdc) {
	drawLine(hdc, 0, 0, 50, 50);
	TCHAR greeting[] = _T("Hello, Windows desktop!");
	drawText(hdc, 5, 5, greeting);
	drawRectangle(hdc, 0, 10, 10, 0);
	drawEllipses(hdc, 300, 400, 400, 200);

	POINT points[3];
	points[0] = { 50, 10 };
	points[1] = { 25, 30 };
	points[2] = { 5, 20 };
	drawPolygon(hdc, points, 3);

	drawCircle(hdc, 300, 300, 50);
}

void drawLine(HDC hdc, int start_x, int start_y, int end_x, int end_y) {
	MoveToEx(hdc, start_x, start_y, NULL);
	LineTo(hdc, end_x, end_y);
}

void drawText(HDC hdc, int x, int y, TCHAR str[]) {
	TextOut(hdc,
		5, 5,
		str, _tcslen(str));
}

void drawRectangle(HDC hdc, int left, int top, int right, int bot) {
	RectangleShape(hdc, left, top, right, bot);
}

void drawEllipses(HDC hdc, int xLeft, int yTop, int xRight, int yBottom) {
	Ellipse(hdc, xLeft, yTop, xRight, yBottom);
}

void drawPolygon(HDC hdc, POINT* p, int sides) {
	Polygon(hdc, p, sides);
}

void drawCircle(HDC hdc, int x, int y, int radius) {
	drawEllipses(hdc, x - radius, y + radius, x + radius, y - radius);
}


*/
/*void drawFillRect(HDC hdc, RECT& rect, HBRUSH brush) {
	FillRect(hdc, &rect, brush);
}*/