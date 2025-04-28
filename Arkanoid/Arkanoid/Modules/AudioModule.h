#pragma once

#include "Module.h"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <memory>

class AudioModule : public Module
{
public:
	AudioModule() = default;
	~AudioModule() override = default;

	bool Start() override { return true; }
	Globals::UpdateState Update(float deltaTime) override;
	Globals::UpdateState PostUpdate(float deltaTime) override { return Globals::UpdateState::Continue; }
	bool Close() override { return true; }

	void PlaySFX(const std::string& name);
	void StopAllSFX();

	void PlayMusic(const std::string& filename, bool loop = true);
	void PauseMusic() { music.pause(); }
	void ResumeMusic() { music.play(); }
	void StopMusic() { music.stop(); }

private:
	void CleanUp();

private:
	std::vector<std::unique_ptr<sf::Sound>> activeSounds;
	sf::Music music;

	float cleanupRate = 1;
	float timer = 0;
};