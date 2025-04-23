#pragma once

#include "Module.h"

class AudioModule : public Module
{
public:
	AudioModule();
	~AudioModule();

	bool Start() override;
	UpdateState Update() override;
	UpdateState PostUpdate() override { return UPDATE_CONTINUE; };
	bool Close() override;

private:

};