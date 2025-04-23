#pragma once

#include "Module.h"

class AudioModule : public Module
{
public:
	AudioModule();
	~AudioModule();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:

};