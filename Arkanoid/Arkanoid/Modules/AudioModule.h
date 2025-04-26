#pragma once

#include "Module.h"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <memory>

class AudioModule : public Module
{
public:
	AudioModule();
	~AudioModule() override;

	bool Start() override;
	UpdateState Update(float deltaTime) override;
	UpdateState PostUpdate(float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

	void PlaySFX(const std::string& name);
	void StopAllSFX();

	void PlayMusic(const std::string& filename, bool loop = true);
	void PauseMusic() { music.pause(); }
	void ResumeMusic() { music.play(); }
	void StopMusic() { music.stop(); };

private:
	void CleanUp();

private:
	std::vector<std::unique_ptr<sf::Sound>> activeSounds;
	sf::Music music;

	float cleanupRate = 1;
	float timer;
};