#pragma once

#include "Globals.h"

#include <vector>
#include <memory>

class Module;
class WindowModule;
class RenderModule;
class GameModule;
class InputModule;
class AudioModule;

class Application
{
public:
	Application();
	~Application();

	bool Start();
	UpdateState Update(float deltaTime);
	bool Close();

public:
	WindowModule* window;
	RenderModule* renderer;
	GameModule* game;
	InputModule* input;
	AudioModule* audio;

private:
	std::vector<Module*> modules;

};

extern Application* App;
