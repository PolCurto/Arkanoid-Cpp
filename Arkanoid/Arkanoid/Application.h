#pragma once

#include "Globals.h"

#include <vector>

class Module;
class WindowModule;
class RenderModule;
class GameModule;
class InputModule;
class AudioModule;
class ResourcesModule;

class Application
{
public:
	Application();
	~Application();

	bool Start();
	Globals::UpdateState Update(float deltaTime);
	bool Close();

public:
	WindowModule* window;
	RenderModule* renderer;
	GameModule* game;
	InputModule* input;
	AudioModule* audio;
	ResourcesModule* resources;

private:
	std::vector<Module*> modules;
};

extern Application* App;
