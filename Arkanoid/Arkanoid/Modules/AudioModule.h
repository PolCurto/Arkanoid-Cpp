#pragma once

#include "Module.h"

class AudioModule : public Module
{
public:
	AudioModule();
	~AudioModule();

	bool Start() override;
	UpdateState Update(const float deltaTime) override;
	UpdateState PostUpdate(const float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

private:

};