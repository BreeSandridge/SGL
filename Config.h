#pragma once
#include <tchar.h>
#include <windows.h>
#include <string>

class config {
public:
	int window_width{};
	int window_height{};

	
	std::string sz_window_class;
	std::string sz_title;

	int current_resolution_width = 1920;
	int current_resolution_height = 1080;

	

	config();
};

