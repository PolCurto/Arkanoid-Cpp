#include "Ball.h"

#include "Application.h"
#include "RenderModule.h"

Ball::Ball() : Entity(EntityType::Ball)
{

}

Ball::Ball(const sf::Vector2f& pos) : Entity(EntityType::Ball, pos)
{

}

Ball::~Ball()
{

}

bool Ball::Start()
{
	shape.setRadius(50.0f);
	shape.setPosition({ 100.0f, 100.0f });
	shape.setFillColor(sf::Color::Green);
	return true;
}

UpdateState Ball::Update(const float deltaTime)
{
	return UPDATE_CONTINUE;
}

UpdateState Ball::Draw()
{
	App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Ball::Close()
{
	return true;
}