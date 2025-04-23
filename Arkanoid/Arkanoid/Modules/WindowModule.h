#pragma once

#include "Module.h"

class WindowModule : public Module
{
public:
	WindowModule();
	~WindowModule();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:

};