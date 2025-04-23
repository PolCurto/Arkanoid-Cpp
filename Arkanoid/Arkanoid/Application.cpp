#include "Application.h"

#include "WindowModule.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "AudioModule.h"
#include "InputModule.h"

Application::Application()
{
	modules.push_back(window = new WindowModule());
	modules.push_back(input = new InputModule());
	modules.push_back(game = new GameModule());
	modules.push_back(audio = new AudioModule());
	modules.push_back(renderer = new RenderModule());
}

Application::~Application()
{
	for (const Module* module : modules)
	{
		delete module;
	}
	modules.clear();
}

bool Application::Start()
{
	bool state = true;

	for (Module* module : modules)
	{
		state = module->Start();
	}

	return state;
}

UpdateState Application::Update()
{
	UpdateState state = UPDATE_CONTINUE;

	for (Module* module : modules)
	{
		state = module->Update();
	}

	return state;
}

bool Application::Close()
{
	bool state = true;

	for (Module* module : modules)
	{
		state = module->Close();
	}

	return state;
}