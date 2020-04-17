#pragma once

///////////////////////////////////////////////////////////////////////////////
// Color
///////////////////////////////////////////////////////////////////////////////
#include "Colors.h"

///////////////////////////////////////////////////////////////////////////////
// Pixel
///////////////////////////////////////////////////////////////////////////////
#include "Point.h"


// Getting started:
//
//   You'll need a recent Visual Studio with the "Desktop development with C++"
//   workload selected during the install process.
//
//   1. Launch Visual Studio and choose File --> New --> Project.
//   2. Type in whatever project name and choose whichever location you like.
//   3. From the "Visual C++" --> "Windows Desktop" category, choose "Windows
//      Desktop Wizard", then click OK.
//
//   4. Choose "Windows Application (.exe)" from the "Application type" box.
//   5. Add a check mark to the "Empty Project" box!
//   6. Click OK.
//
//   7. Copy the following 3 files from Immediate2D into your project's folder:
//      - drawing.cpp
//      - drawing.h
//      - example1_helloWorld.cpp


// Tinker with these to change the size of the window
//
// (All of the examples assume a Width of 160 and Height of 120)
//
static constexpr int Width = 160;
static constexpr int Height = 120;
static constexpr int PixelScale = 5;



// A useful constant (equal to two pi) to help with trigonometry or circles
static constexpr double Tau = 6.283185307179586476925286766559;










///////////////////////////////////////////////////////////////////////////////
// Drawing Backend
///////////////////////////////////////////////////////////////////////////////


// For all of the following drawing functions, x is between 0 and Width;
// y is between 0 and Height.
//
// In computer graphics, y=0 is the top of the screen and it increases
// downward (contrary to the typical mathematics convention).


// Draws a single dot at (x, y) in the given color
void SetPixel(int x, int y, Color c);

// Draws a line from (x1, y1) to (x2, y2) with a given stroke thickness
// (in units of pixels) in the given color
void DrawLine(int x1, int y1, int x2, int y2, int thickness, Color c);

// Draws a circle centered at (x, y) with a given radius (in pixels).  The
// filled parameter controls whether to draw a single pixel outline or to
// completely fill the circle with the passed-in color.
void DrawCircle(int x, int y, int radius, Color c, bool filled);

// Draws a rectangle with upper-left corner at (x, y) with the given width
// and height.  The filled parameter controls whether to draw a single pixel
// outline or to completely fill the rectangle with the passed-in color.
void DrawRectangle(int x, int y, int width, int height, Color c, bool filled);


///////////////////////////////////////////////////////////////////////////////
// Drawing Pipeline
///////////////////////////////////////////////////////////////////////////////

void DrawPoint(Point p);

void DrawPoint(int x, int y, Color c);


///////////////////////////////////////////////////////////////////////////////
// WIP
///////////////////////////////////////////////////////////////////////////////


void DrawLine(Vertex v1, Vertex v2, int thickness, Color c);
void DrawLine(Vertex v1, Vertex v2, int thickness);
void DrawLine(Vertex v1, Vertex v2, Color c);
void DrawLine(Vertex v1, Vertex v2);






// Clears the screen to the given color (or Black if no color passed in)
void Clear(Color c = Black);

// Retrieves the color at the given location.  Test against specific colors:
//     if (GetPixel(playerX, playerY) == Black) ...
//
Color GetPixel(int x, int y);




// OPTIONAL!  When anti-aliasing is enabled, all drawing (except single pixels)
// is done with soft edges.  Can be toggled at any time.  Disabled by default.
void UseAntiAliasing(bool enabled);

// OPTIONAL!  When double buffering is enabled, instead of drawing directly to
// the screen, you'll be drawing to a "back buffer".  This lets you compose
// entire scenes or erase and redraw objects without any visible flicker.
//
// Once enabled, you must call the Present function (see below) in order to
// see anything!
//
// Disabled by default
//
void UseDoubleBuffering(bool enabled);

// OPTIONAL!  Only necessary when you've enabled double buffering.  Call when
// you would like to simultaneously show all new drawing performed since your
// previous Present().
//
// Tip: If called at regular intervals, you can achieve an animation effect.
//
// If double buffering is enabled, this MUST be called after you're finished
// drawing in order to see anything!
//
void Present();




///////////////////////////////////////////////////////////////////////////////
// Utility
///////////////////////////////////////////////////////////////////////////////


// When you are ready to end your program, you may call this to automatically
// close the window, too.  If you don't, the window will simply show whatever
// was drawn most recently, forever.
//
// NOTE: If you're NOT ready to end your program, don't call this!  As a side-
//       effect, your main function will be terminated immediately.
//
void CloseWindow();


// Delays for the given number of milliseconds.  Useful for animation.
void Wait(int milliseconds);




///////////////////////////////////////////////////////////////////////////////
// Interactivity (Mouse & Keyboard)
///////////////////////////////////////////////////////////////////////////////


// In order to make good use of mouse and keyboard input, you'll want to set up
// your program so that input is checked and drawing is performed repeatedly,
// in a loop. Game programmers usually call this the "game loop".


// Returns the most recently pressed keyboard character.  For special, non-
// printable characters, test against the values in Keys, below.
//
// NOTE: To avoid reporting the same key press forever, this function only
//       returns the value ONCE and will subsequently report a value of zero
//       until the next key is pressed.  If you need to use this value more
//       than once, store it in a variable first!
//
char LastKey();

// Used to check the results of LastKey() against non-printable keys:
//     const char key = LastKey();
//     if (key == Enter) ...
//     if (key == Left) ...
//     if (key == Esc) ...
//     if (key == '&') ...
//     if (key == 'r') ...
//     if (key == ' ') ...
//
enum Keys
{
	Left = 0x11,
	Up,
	Right,
	Down,

	Backspace = 8,
	Enter = 13,
	Esc = 27,
	Tab = 9,
};


// Is the mouse button currently being held down?
bool LeftMousePressed();
bool RightMousePressed();
bool MiddleMousePressed();

// Retrieves the current mouse coordinates, or (-1, -1) if the mouse isn't
// currently hovering over our window
int MouseX();
int MouseY();








