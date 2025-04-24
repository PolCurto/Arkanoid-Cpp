#include "Block.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "Enlarger.h"
#include "Reducer.h"
#include "Destroyer.h"

#include <random>

Block::Block() : Entity(EntityType::Block)
{

}

Block::Block(const sf::Vector2f position, const sf::Color color) : color(color), Entity(EntityType::Block, position)
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
	size.x = 75;
	size.y = 30.0f;
	shape.setSize(size);

	shape.setPosition(position);

	shape.setFillColor(color);
	shape.setOutlineThickness(-1.0f);
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
	// Randomly spawn an item
	// Code from: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distr(0.0f, 1.0f);

	if (distr(gen) < itemRate)
	{
		const sf::Vector2 posToSpawn(position.x + size.x / 3.0f, position.y);

		// Pick a random item type
		std::uniform_int_distribution<> distr(0, 2);
		switch (distr(gen))
		{
		case 0:		
			App->game->AddEntity(new Enlarger(posToSpawn));
			break;

		case 1:
			App->game->AddEntity(new Reducer(posToSpawn));
			break;

		case 2:
			App->game->AddEntity(new Destroyer(posToSpawn));
			break;
		}
	}

	// Move the block far away to avoid destroying it
	position = { 10000, 10000 };
	shape.setPosition(position);
}