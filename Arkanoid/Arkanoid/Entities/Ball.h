#pragma once

#include "Entity.h"

class Ball : public Entity
{
public:
	Ball();
	~Ball();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:

};