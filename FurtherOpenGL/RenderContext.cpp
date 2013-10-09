#include "RenderContext.h"
#include "GraphicsWindow.h"


RenderContext::RenderContext(void)
{
}


RenderContext::~RenderContext(void)
{
}

void RenderContext::Initialize(Window& window)
{
	activeWindow = &window;
}