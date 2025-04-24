#include "Item.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "Paddle.h"

Item::Item(const sf::Vector2f position, const EntityType type) : Entity(type, position)
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

UpdateState Item::Update(const float deltaTime)
{
	Move(deltaTime);
	return UPDATE_CONTINUE;
}

UpdateState Item::Draw()
{
	App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Item::Close()
{
	return true;
}