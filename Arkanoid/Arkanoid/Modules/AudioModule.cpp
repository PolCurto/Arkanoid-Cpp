#include "AudioModule.h"

#include "Application.h"
#include "ResourcesModule.h"

#include <SFML/Audio.hpp>
#include <iostream>

AudioModule::AudioModule()
{

}

AudioModule::~AudioModule()
{

}

bool AudioModule::Start()
{
	return true;
}

UpdateState AudioModule::Update(float deltaTime)
{
	timer += deltaTime;
	if (timer >= cleanupRate)
	{
		timer = 0;
		CleanUp();
	}

	return UPDATE_CONTINUE;
}

bool AudioModule::Close()
{
	return true;
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
	std::unique_ptr<sf::Sound> sound = std::make_unique<sf::Sound>(App->resources->GetAudio(name));
	sound->setVolume(30);
	sound->play();
	activeSounds.emplace_back(std::move(sound));
}

void AudioModule::StopAllSFX()
{
	for (int i = 0; i < activeSounds.size(); ++i)
	{
		activeSounds[i]->stop();
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
				return sound->getStatus() != sf::Sound::Status::Playing;
			}), 
		activeSounds.end());
}