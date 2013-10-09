#include "OpenGLRenderContext.h"
#include "GraphicsWindow.h"
#include <gl\GL.h>
#include <gl\GLU.h>

OpenGLRenderContext::OpenGLRenderContext(void)
{
}


OpenGLRenderContext::~OpenGLRenderContext(void)
{
	if (hrc)
	{
		wglMakeCurrent(NULL, NULL);	// free rendering memory
		wglDeleteContext(hrc);		// Delete our OpenGL Rendering Context
	}

	if (hdc) 
		ReleaseDC(activeWindow->GetHandleToWindow(), hdc);			// Release our HDC from memory
}

void OpenGLRenderContext::Initialize(Window& window)
{
	RenderContext::Initialize(window);
	hdc = GetDC(window.GetHandleToWindow());//  sets  global HDC

    if (!SetOGLPixelFormat())				//  sets  pixel format
        PostQuitMessage (0);


    hrc = wglCreateContext(hdc);	//  creates  rendering context from  hdc
    wglMakeCurrent(hdc, hrc);		//	Use this HRC.

	SetOGLPixelFormat();
	SetViewport();	// Setup the Screen
}

bool OpenGLRenderContext::SetOGLPixelFormat()
{
    PIXELFORMATDESCRIPTOR pfd = {0}; 
    int pixelformat;
 
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);	// Set the size of the structure
    pfd.nVersion = 1;							// Always set this to 1
	// Pass in the appropriate OpenGL flags
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
    pfd.dwLayerMask = PFD_MAIN_PLANE;			// standard mask (this is ignored anyway)
    pfd.iPixelType = PFD_TYPE_RGBA;				// RGB and Alpha pixel type
    pfd.cColorBits = COLOUR_DEPTH;				// Here we use our #define for the color bits
    pfd.cDepthBits = COLOUR_DEPTH;				// Ignored for RBA
    pfd.cAccumBits = 0;							// nothing for accumulation
    pfd.cStencilBits = 0;						// nothing for stencil
 
	//Gets a best match on the pixel format as passed in from device
    if ( (pixelformat = ChoosePixelFormat(hdc, &pfd)) == false ) 
    { 
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
        return false; 
    } 
 
	//sets the pixel format if its ok. 
    if (SetPixelFormat(hdc, pixelformat, &pfd) == false) 
    { 
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
        return false; 
    } 
 
    return true;
}

void OpenGLRenderContext::OnResize()
{
	SetViewport();
}

void OpenGLRenderContext::SetViewport()
{
	int height = activeWindow->GetHeight();
	int width = activeWindow->GetWidth();

	if (height==0)	// Prevent A Divide By Zero error
	{
		height=1;	// Make the Height Equal One
	}

	glViewport(0,0,width,height);		//  Create the OpenGL 'window' to fill the actual window

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);// Select The Modelview Matrix
	glLoadIdentity();// Reset The Modelview Matrix
}

void OpenGLRenderContext::FlipBuffers()
{
	SwapBuffers(hdc);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}


