#pragma once

#include "Entity.h"

class Paddle : public Entity
{
public:
	Paddle();
	~Paddle();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:

};