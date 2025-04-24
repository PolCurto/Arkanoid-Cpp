#pragma once

#include "Globals.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

enum class EntityType: uint8_t
{
	Block,
	Paddle,
	Ball,
	Enlarger,
	Reducer,
	Destroyer,
	UI
};

class Entity
{
public:
	Entity(const EntityType type) : type(type) {};
	Entity(const EntityType type, const sf::Vector2f& pos) : type(type), position(pos) {};
	~Entity() = default;

	virtual bool Start() { return true; };
	virtual UpdateState Update(float deltaTime) { return UPDATE_CONTINUE; };
	virtual UpdateState Draw() { return UPDATE_CONTINUE; };
	virtual bool Close() { return true; };

	EntityType GetType() const { return type; }
	sf::Vector2f GetPosition() const { return position; }
	sf::Vector2f GetSize() const { return size; }

protected:
	EntityType type;
	sf::Vector2f position;
	sf::Vector2f size;
};