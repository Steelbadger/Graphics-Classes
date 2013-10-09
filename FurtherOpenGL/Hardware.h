#pragma once
#include "mouse.h"
#include "Vector2.h"

#include <windows.h>
#include <time.h>

class HardwareState
{
public:

	static HardwareState& GetInstance();
	~HardwareState(void);

	void Message(UINT, WPARAM, LPARAM);

	void Update();

	Vector2 GetMousePosition() {return mouse.Position();}
	Vector2 GetMouseDeltaMovement() {return mouse.FrameDeltaMovement();}

	bool MouseButton(Mouse::Buttons b) {return mouse.Button(b);}
	bool MousePressed(Mouse::Buttons b) {return mouse.Pressed(b);}
	bool MouseReleased(Mouse::Buttons b) {return mouse.Released(b);}
	bool Button(char key) {return keys[key];}
	bool Pressed(char key) {return pressed[key];}
	bool Released(char key) {return released[key];}
	bool Button(int key) {return keys[key];}
	bool Pressed(int key) {return pressed[key];}
	bool Released(int key) {return released[key];}
	bool WindowHasChanged(){return windowWasChanged;}

	void SetMouseLocked(int x, int y){mouse.SetLocked(x, y);}

	bool CheckMouseWheel(){return mouse.CheckWheelMoved();}
	int GetMouseWheelDelta(){return mouse.GetWheelDelta();}

	double GetTimeForLastFrame() {return timeForLastFrame/CLOCKS_PER_SEC;}
	double GetTimeSinceLastFrame();

private:

	HardwareState(void);

	bool keys[256];
	bool pressed[256];
	bool released[256];
	bool oldkey[256];

	bool windowChange;
	bool windowWasChanged;

	double timeForLastFrame;
	double lastTime;
	double currentTime;

	Mouse mouse;

	void KeyDown(UINT);
	void KeyUp(UINT);

	static HardwareState* instance;

	int screenWidth;
	int screenHeight;
};