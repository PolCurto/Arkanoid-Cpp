#pragma once

#include "Module.h"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

class AudioModule : public Module
{
public:
	AudioModule();
	~AudioModule();

	bool Start() override;
	UpdateState Update(float deltaTime) override;
	UpdateState PostUpdate(float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

private:
	sf::SoundBuffer buffer;
	sf::Music music;
};