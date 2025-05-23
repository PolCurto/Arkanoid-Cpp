#include "AudioModule.h"

#include "Application.h"
#include "ResourcesModule.h"

#include <SFML/Audio.hpp>

Globals::UpdateState AudioModule::Update(float deltaTime)
{
	timer += deltaTime;
	if (timer >= cleanupRate)
	{
		timer = 0;
		CleanUp();
	}

	return Globals::UpdateState::Continue;
}

void AudioModule::PlayMusic(const std::string& filename, bool loop)
{
	if (music.openFromFile(filename))
	{
		music.setVolume(20);
		music.setLooping(loop);
		music.play();
	}
}

void AudioModule::PlaySFX(const std::string& name)
{
	const sf::SoundBuffer* buffer = App->resources->GetAudio(name);
	if (!buffer) return;

	std::unique_ptr<sf::Sound> sound = std::make_unique<sf::Sound>(*buffer);
	sound->setVolume(30);
	sound->play();
	activeSounds.emplace_back(std::move(sound));
}

void AudioModule::StopAllSFX()
{
	for (const auto& sound : activeSounds)
	{
		sound->stop();
	}
}

void AudioModule::CleanUp()
{
	// Remove finished sounds
	// Code from https://stackoverflow.com/questions/17270837/stdvector-removing-elements-which-fulfill-some-conditions
	activeSounds.erase(
		std::remove_if(
			activeSounds.begin(), activeSounds.end(),
			[](const std::unique_ptr<sf::Sound>& sound) {
				return sound->getStatus() == sf::Sound::Status::Stopped;
			}), 
		activeSounds.end());
}