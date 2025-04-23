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
	size.x = 150.0f;
	size.y = 20.0f;
	shape.setSize(size);

	position.x = 400.0f;
	position.y = 700.0f;
	shape.setPosition(position);

	shape.setFillColor(sf::Color({ 99, 164, 214 }));
	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor({ sf::Color({15, 15, 15}) });
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
	float finalPos = position.x + currentVelocity * deltaTime;

	// Avoid going out of bounds
	if (finalPos > 0 && finalPos + size.x < SCREEN_WIDTH)
	{
		position.x = finalPos;
		shape.setPosition(position);
	}
}