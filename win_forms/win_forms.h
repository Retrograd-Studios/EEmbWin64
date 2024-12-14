
#pragma once

#include "stdint.h"

#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 200

extern "C" {
	__declspec(dllexport) int32_t EEmbCreateWindow(const char* title, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
	//int32_t EEmbCreateWindow(const char* title, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
}

