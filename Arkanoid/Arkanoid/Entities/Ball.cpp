#include "Ball.h"

Ball::Ball()
{

}

Ball::~Ball()
{

}

bool Ball::Start()
{
	return true;
}

UpdateState Ball::Update()
{
	return UPDATE_CONTINUE;
}

bool Ball::Close()
{
	return true;
}