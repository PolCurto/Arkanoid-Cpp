#include "Paddle.h"

#include "Application.h"
#include "RenderModule.h"
#include "InputModule.h"

Paddle::Paddle() : Block(EntityType::Paddle)
{

}

Paddle::~Paddle()
{

}

bool Paddle::Start()
{
	shape.setSize({ 100.0f, 50.0f });

	position.x = 400.0f;
	position.y = 500.0f;
	shape.setPosition(position);

	shape.setFillColor(sf::Color::Blue);

	return true;
}

UpdateState Paddle::Update(const float deltaTime)
{
	currentVelocity = 0;

	GetInputs();
	Move(deltaTime);

	return UPDATE_CONTINUE;
}

UpdateState Paddle::Draw()
{
	App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Paddle::Close()
{
	return true;
}

void Paddle::GetInputs()
{
	if (App->input->IsKeyDown(sf::Keyboard::Scan::Left))
	{
		currentVelocity -= velocity;
	}

	if (App->input->IsKeyDown(sf::Keyboard::Scan::Right))
	{
		currentVelocity += velocity;
	}
}

void Paddle::Move(const float deltaTime)
{
	position.x += currentVelocity * deltaTime;
	shape.setPosition(position);
}