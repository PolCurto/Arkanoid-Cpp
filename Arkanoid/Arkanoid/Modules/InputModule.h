#pragma once

#include "Module.h"

class InputModule : public Module
{
public:
	InputModule();
	~InputModule();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:

};