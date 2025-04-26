#pragma once

#include "Globals.h"

class Module
{
public:
	Module() = default;
	virtual ~Module() = default;

	virtual bool Start() = 0;
	virtual UpdateState Update(float deltaTime) = 0;
	virtual UpdateState PostUpdate(float deltaTime) = 0;
	virtual bool Close() = 0;
};