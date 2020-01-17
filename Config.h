#pragma once
#include <tchar.h>
#include <windows.h>
#include <string>

class Config {
public:
	int windowWidth;
	int windowHeight;

	
	std::string szWindowClass;
	std::string szTitle;

	int currentResolutionWidth = 1920;
	int currentResolutionHeight = 1080;

	

	Config();
};

