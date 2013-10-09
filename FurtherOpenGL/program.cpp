#include "program.h"
#include <gl\GL.h>
#include <iostream>

Program::Program(void)
{
	hardware = &HardwareState::GetInstance();
}


Program::~Program(void)
{
}

void Program::Initialize(HINSTANCE hInstance)
/*-------------------------------------------------------------------------*\
|	Purpose:	Create a window, initialise OpenGL context and retrieve		|
|				machine and driver specs									|
|																			|
|	Parameters:	hInstance of the process									|
|																			|
|	Returns:	None.														|
|																			|
\*-------------------------------------------------------------------------*/
{

	//  Create a new window called OpenGL Framework, 1000 pix long and 500 pix tall
	window.Create("Basic Program", 640, 512, (WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN), false, hInstance);

	//  Move the cursor to the middle of the window
	window.SetCursorToCentre();
	context.Initialize(window);

}

void Program::MainLoop()
/*-------------------------------------------------------------------------*\
|	Purpose:	The primary application loop, handles calling of all		|
|				update functions											|
|																			|
|	Parameters:	None.														|
|																			|
|	Returns:	None.														|
|																			|
\*-------------------------------------------------------------------------*/
{

	if (hardware->WindowHasChanged()) {
		context.OnResize();
	}

	//  Slow down incase of really fast machine
	if (hardware->GetTimeSinceLastFrame() >= 10) {
		//  Update the input state
		hardware->Update();

		glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(-0.75f, -0.75f, 0.5f);
		glVertex3f(0.75f, 0.75f, 0.5f);
		glVertex3f(0.75f, -0.75f, 0.5f);
		glVertex3f(-0.75f, 0.75f, 0.5f);
		glEnd();


		context.FlipBuffers();
	}

	//  Exit the program
	if (hardware->Pressed(VK_ESCAPE))
		exit(0);
}
