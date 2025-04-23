#include "Paddle.h"

Paddle::Paddle() : Entity(EntityType::Paddle)
{

}

Paddle::~Paddle()
{

}

bool Paddle::Start()
{
	return true;
}

UpdateState Paddle::Update()
{
	return UPDATE_CONTINUE;
}

bool Paddle::Close()
{
	return true;
}