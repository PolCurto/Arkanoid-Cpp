#pragma once

#include "Entity.h"

class Block : public Entity
{
public:
	Block();
	~Block();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:

};