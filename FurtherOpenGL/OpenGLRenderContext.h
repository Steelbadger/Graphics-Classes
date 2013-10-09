#pragma once
#include "RenderContext.h"

#include <Windows.h>

class Window;

class OpenGLRenderContext: RenderContext
{
public:
	OpenGLRenderContext(void);
	virtual ~OpenGLRenderContext(void);
	virtual void Initialize(Window& window);
	virtual void FlipBuffers();
	virtual void OnResize();
private:
	bool SetOGLPixelFormat();
	void SetViewport();

	HGLRC hrc;			//hardware RENDERING CONTEXT
	HDC hdc;			//hardware DEVICE CONTEXT
	static const int COLOUR_DEPTH = 16;
};

