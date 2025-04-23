#include "Block.h"

#include "Application.h"
#include "RenderModule.h"

Block::Block() : Entity(EntityType::Block)
{

}

Block::Block(const float x, const float y) : Entity(EntityType::Block, {x, y})
{

}

Block::Block(const EntityType type) : Entity(type)
{

}

Block::~Block()
{

}

bool Block::Start()
{
	size.x = 80.0f;
	size.y = 30.0f;
	shape.setSize(size);

	shape.setPosition(position);

	shape.setFillColor(sf::Color({ 199, 61, 46 }));
	shape.setOutlineThickness(1.0f);
	shape.setOutlineColor(sf::Color({ 15, 15, 15 }));

	return true;
}

UpdateState Block::Update(const float deltaTime)
{
	return UPDATE_CONTINUE;
}

UpdateState Block::Draw()
{
	App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Block::Close()
{
	return true;
}

void Block::OnHit(const int damage)
{
	life -= damage;

	if (life == 0) Destroy();
}

void Block::Destroy()
{
	position = { 10000, 10000 };
	shape.setPosition(position);
}