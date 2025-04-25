#include "Application.h"

#include "WindowModule.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "AudioModule.h"
#include "InputModule.h"
#include "ResourcesModule.h"

Application::Application()
{
	modules.push_back(window = new WindowModule());
	modules.push_back(resources = new ResourcesModule());
	modules.push_back(renderer = new RenderModule(window->GetWindow()));
	modules.push_back(input = new InputModule(window->GetWindow()));
	modules.push_back(game = new GameModule());
	modules.push_back(audio = new AudioModule());
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
		if (!state) break;
	}

	return state;
}

UpdateState Application::Update(float deltaTime)
{
	UpdateState state = UPDATE_CONTINUE;

	for (Module* module : modules)
	{
		state = module->Update(deltaTime);
		if (state != UPDATE_CONTINUE) break;
	}

	if (state != UPDATE_CONTINUE) return state;

	for (Module* module : modules)
	{
		state = module->PostUpdate(deltaTime);
		if (state != UPDATE_CONTINUE) break;
	}

	return state;
}

bool Application::Close()
{
	bool state = true;

	for (Module* module : modules)
	{
		state = module->Close();
		if (!state) break;
	}

	return state;
}