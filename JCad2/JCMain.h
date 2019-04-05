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
	void ProcesImput();
	void UpdateModel();
	void Render();
private:
	Window wnd;
	std::string ProjectName;
	ChiliTimer timer;
};