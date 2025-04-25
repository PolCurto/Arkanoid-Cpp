#include "Item.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "Paddle.h"

Item::Item(const sf::Vector2f position) : Entity(EntityType::Item, position)
{

}

Item::~Item()
{

}

bool Item::Start()
{
	shape.setRadius(15.0);
	shape.setPosition(position);
	size = shape.getLocalBounds().size;
	return true;
}

UpdateState Item::Update(float deltaTime)
{
	if (!isEnabled) return UPDATE_CONTINUE;

	Move(deltaTime);
	CheckCollisions();
	return UPDATE_CONTINUE;
}

UpdateState Item::Draw()
{
	if (isEnabled) App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Item::Close()
{
	return true;
}

bool Item::CheckCollisions()
{
	bool isColliding = false;

	if (shape.getGlobalBounds().findIntersection(App->game->GetPaddle()->GetBoundingBox()))
	{
		isColliding = true;
		isEnabled = false;
	}

	return isColliding;
}