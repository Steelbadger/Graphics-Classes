#pragma once
#include <Windows.h>
#include <map>

class Window
{
public:
	Window(void);
	Window(LPSTR WindowName, int width, int height, HINSTANCE hInstance);
	Window(LPSTR WindowName, int width, int height, HINSTANCE hInstance, bool FullScreen, DWORD Style);
	void Create(LPSTR strWindowName, int width, int height, DWORD dwStyle, bool bFullScreen, HINSTANCE hInstance);

	~Window(void);

	void OnResize();
	void OnMove();
//	void FlipBuffers();

	int GetWidth(){return graphicsRect.right;}
	int GetHeight(){return graphicsRect.bottom;}
	int GetGraphicsYOffset(){return borderWidth+titleCaptionHeight;}
	int GetGraphicsXOffset(){return borderWidth;}
	int GetX(){return windowRect.left;};
	int GetY(){return windowRect.top;}

	void SetCursorToCentre();
	void SetMouseLockedCentre();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static Window* GetWindowReference(HWND hWnd);

//	HDC GetHandleToDeviceContext(){return hdc;};
	HWND GetHandleToWindow(){return handleToWindow;}
//	HGLRC GetRenderingContext(){return hrc;}
//	bool SetWindowPixelFormat(HDC hdc);

private:

	HWND handleToWindow;
//	HDC hdc;
//	HGLRC hrc;			//hardware RENDERING CONTEXT
	WNDCLASS wcex;
	RECT graphicsRect;
	RECT windowRect;

	int gWidth, gHeight;
	int borderWidth;
	int titleCaptionHeight;
	static std::map<HWND,Window*>WindowMap;
//	static int cxSource, cySource;

	static const int COLOUR_DEPTH = 16;
};

