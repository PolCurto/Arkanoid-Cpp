#include "ResourcesModule.h"

#include "SFML/Graphics.hpp"
#include <iostream>

bool ResourcesModule::Start()
{
	// Load fonts
	sf::Font font;
	if (font.openFromFile("HomeVideo-BLG6G.ttf")) fonts.insert({ "HomeVideo", font });

	// Load audio files
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile("Audio/paddleBounce.ogg")) audioBuffers.insert({ "paddleBounce", buffer });
	if (buffer.loadFromFile("Audio/wallBounce.ogg")) audioBuffers.insert({ "wallBounce", buffer });
	if (buffer.loadFromFile("Audio/blockHit.ogg")) audioBuffers.insert({ "blockHit1", buffer });
	if (buffer.loadFromFile("Audio/shrink.wav")) audioBuffers.insert({ "shrink", buffer });
	if (buffer.loadFromFile("Audio/grow.wav")) audioBuffers.insert({ "grow", buffer });
	if (buffer.loadFromFile("Audio/destroyer.wav")) audioBuffers.insert({ "destroyer", buffer });
	if (buffer.loadFromFile("Audio/gameOver.ogg")) audioBuffers.insert({ "gameOver", buffer });

	// Load textures
	sf::Texture texture;
	if (texture.loadFromFile("Textures/background.png")) textures.insert({ "background", texture });
	if (texture.loadFromFile("Textures/a.png")) textures.insert({ "a", texture });
	if (texture.loadFromFile("Textures/b.png")) textures.insert({ "b", texture });
	if (texture.loadFromFile("Textures/c.png")) textures.insert({ "c", texture });
	if (texture.loadFromFile("Textures/gun.png")) textures.insert({ "gun", texture });

	return true;
}

const sf::SoundBuffer& ResourcesModule::GetAudio(const std::string& name) const
{
	const auto& it = audioBuffers.find(name);
	if (it != audioBuffers.end()) return it->second;
	else std::cerr << "Could no find audio with name: " + name << std::endl;
}

const sf::Font& ResourcesModule::GetFont(const std::string& name) const
{
	const auto& it = fonts.find(name);
	if (it != fonts.end()) return it->second;
	else std::cerr << "Could no find font with name: " + name << std::endl;
}

const sf::Texture& ResourcesModule::GetTexture(const std::string& name) const
{
	const auto& it = textures.find(name);
	if (it != textures.end()) return it->second;
	else std::cerr << "Could no find texture with name: " + name << std::endl;
}