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
	ResourcesModule();
	~ResourcesModule();

	bool Start() override;
	UpdateState Update(float deltaTime) override;
	UpdateState PostUpdate(float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

	const sf::SoundBuffer& GetAudio(const std::string& name) { return audioBuffers.at(name); }
	const sf::Texture& GetTexture(const std::string& name) { return textures.at(name); }
	const sf::Font& GetFont(const std::string& name) { return fonts.at(name); }

private:
	std::unordered_map<std::string, sf::SoundBuffer> audioBuffers;
	std::unordered_map<std::string, sf::Texture> textures;
	std::unordered_map<std::string, sf::Font> fonts;
};
