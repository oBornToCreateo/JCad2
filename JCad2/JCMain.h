#pragma once
#include "Window.h"
#include "ChiliTimer.h"

class JCMain
{
public:
	JCMain();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	ChiliTimer timer;
};