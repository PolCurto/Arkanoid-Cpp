#include "Block.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "Speeder.h"
#include "Gun.h"
#include "Destroyer.h"

#include <random>

Block::Block(const sf::Vector2f position, const sf::Color color, const int score) : color(color), score(score), Entity(EntityType::Block, position) {}

bool Block::Start()
{
	size.x = 75;
	size.y = 30.0f;
	shape.setSize(size);

	shape.setPosition(position);

	shape.setFillColor(color);
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor({ 15, 15, 15 });

	// Set if has item or not at the creation with a random chance
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
			itemOnDestroy = new Speeder(posToSpawn);
			break;

		case 1:
			itemOnDestroy = new Gun(posToSpawn);
			break;

		case 2:
			itemOnDestroy = new Destroyer(posToSpawn);
			break;
		}
		App->game->AddEntity(itemOnDestroy);
		itemOnDestroy->SetEnabled(false);
	}

	return true;
}

Globals::UpdateState Block::Draw() const
{
	if (isEnabled) App->renderer->Draw(shape, Layer::Front);
	return Globals::UpdateState::Continue;
}

void Block::OnHit(const int damage)
{
	life -= damage;
	if (life == 0)
	{
		isEnabled = false;
		App->game->AddScore(score);
		if (itemOnDestroy) itemOnDestroy->SetEnabled(true);
	}
}