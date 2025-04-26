#pragma once

#include "Globals.h"

class Module
{
public:
	Module() = default;
	virtual ~Module() = default;

	virtual bool Start() = 0;
	virtual Globals::UpdateState Update(float deltaTime) = 0;
	virtual Globals::UpdateState PostUpdate(float deltaTime) = 0;
	virtual bool Close() = 0;
};