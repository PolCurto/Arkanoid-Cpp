#include "Item.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "Paddle.h"

bool Item::Start()
{
	shape.setRadius(15.0);
	shape.setPosition(position);
	size = shape.getLocalBounds().size;
	return true;
}

Globals::UpdateState Item::Update(float deltaTime)
{
	if (!isEnabled) return Globals::UpdateState::Continue;

	Move(deltaTime);
	CheckCollisions();
	return Globals::UpdateState::Continue;
}

Globals::UpdateState Item::Draw()
{
	if (isEnabled) App->renderer->Draw(shape, Layer::Front);
	return Globals::UpdateState::Continue;
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