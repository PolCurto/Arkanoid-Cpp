#pragma once

#include "Module.h"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <unordered_map>
#include <string>

class ResourcesModule : public Module
{
public:
	ResourcesModule() = default;
	~ResourcesModule() = default;

	bool Start() override;
	UpdateState Update(float deltaTime) override { return UPDATE_CONTINUE; };
	UpdateState PostUpdate(float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override { return true; };

	const sf::SoundBuffer& GetAudio(const std::string& name) const;
	const sf::Texture& GetTexture(const std::string& name) const;
	const sf::Font& GetFont(const std::string& name) const;

private:
	std::unordered_map<std::string, sf::SoundBuffer> audioBuffers;
	std::unordered_map<std::string, sf::Texture> textures;
	std::unordered_map<std::string, sf::Font> fonts;
};
