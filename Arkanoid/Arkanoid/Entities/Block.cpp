#include "Block.h"

#include "Application.h"
#include "RenderModule.h"

Block::Block() : Entity(EntityType::Block)
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
	shape.setSize({ 100.0f, 50.0f });
	shape.setPosition({ 300.0f, 200.0f });
	shape.setFillColor(sf::Color::Red);

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