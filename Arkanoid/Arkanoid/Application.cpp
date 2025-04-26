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
	for (Module* module : modules)
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

Globals::UpdateState Application::Update(float deltaTime)
{
	Globals::UpdateState state = Globals::UpdateState::Continue;

	for (Module* module : modules)
	{
		state = module->Update(deltaTime);
		if (state != Globals::UpdateState::Continue) break;
	}

	if (state != Globals::UpdateState::Continue) return state;

	for (Module* module : modules)
	{
		state = module->PostUpdate(deltaTime);
		if (state != Globals::UpdateState::Continue) break;
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