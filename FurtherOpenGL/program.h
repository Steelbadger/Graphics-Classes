#pragma once
#include "GraphicsWindow.h"
#include "Hardware.h"
#include "OpenGLRenderContext.h"

#include <Windows.h>

class Program
{
public:
	Program(void);
	~Program(void);

	void Initialize(HINSTANCE hInstance);
	void MainLoop();
private:
	Window window;
	HardwareState* hardware;
	OpenGLRenderContext context;
};