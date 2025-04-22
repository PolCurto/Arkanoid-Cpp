#pragma once

#include "Globals.h"

#include <vector>

class WindowModule;
class RenderModule;

class Application
{
public:
	Application();
	~Application();

	bool Start();
	UpdateState Update();
	bool Close();

private:

};

extern Application* App;
