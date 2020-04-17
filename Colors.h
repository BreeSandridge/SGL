#pragma once
// This declares a synonym: whenever you see "Color", it means "unsigned int"
using Color = unsigned int;

// Creates a color that can be used with the other drawing functions.
// The r, g, and b parameters are color intensities between 0 and 255.
Color MakeColor(int r, int g, int b);

// Here are some colors (from the old, 16-color EGA palette) to get you
// started.  You can make your own using the same MakeColor function.
static const Color Black = MakeColor(0, 0, 0);
static const Color Blue = MakeColor(0, 0, 170);
static const Color Green = MakeColor(0, 170, 0);
static const Color Cyan = MakeColor(0, 170, 170);
static const Color Red = MakeColor(170, 0, 0);
static const Color Magenta = MakeColor(170, 0, 170);
static const Color Brown = MakeColor(170, 85, 0);
static const Color LightGray = MakeColor(170, 170, 170);
static const Color DarkGray = MakeColor(85, 85, 85);
static const Color LightBlue = MakeColor(85, 85, 170);
static const Color LightGreen = MakeColor(85, 255, 85);
static const Color LightCyan = MakeColor(85, 255, 255);
static const Color LightRed = MakeColor(255, 85, 85);
static const Color LightMagenta = MakeColor(255, 85, 255);
static const Color Yellow = MakeColor(255, 255, 85);
static const Color White = MakeColor(255, 255, 255);