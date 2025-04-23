#pragma once

#include "Globals.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

enum class EntityType
{
	Block,
	Paddle,
	Ball
};

class Entity
{
public:
	Entity(const EntityType type) : type(type) {};
	Entity(const EntityType type, const sf::Vector2f& pos) : type(type), position(pos) {};
	~Entity() = default;

	virtual bool Start() { return true; };
	virtual UpdateState Update() { return UPDATE_CONTINUE; };
	virtual UpdateState Draw() { return UPDATE_CONTINUE; };
	virtual bool Close() { return true; };

protected:
	EntityType type;
	sf::Vector2f position;
};