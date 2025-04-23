#pragma once

#include "Globals.h"

class Entity
{
public:
	Entity() = default;
	~Entity() = default;

	virtual bool Start() = 0;
	virtual UpdateState Update() = 0;
	virtual bool Close() = 0;

	//TODO: Maybe not interface, can have some attributes like position, size, etc.
};