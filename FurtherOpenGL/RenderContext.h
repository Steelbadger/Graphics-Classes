#pragma once

class Window;

class RenderContext
{
public:
	RenderContext(void);
	virtual void Initialize(Window& window);
	virtual void FlipBuffers() = 0;
	virtual void OnResize() = 0;
	virtual ~RenderContext(void);
protected:
	Window* activeWindow;
};

