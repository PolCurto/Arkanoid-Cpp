#pragma once

#include "Module.h"

class RenderModule : public Module
{
public:
	RenderModule();
	~RenderModule();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:


};