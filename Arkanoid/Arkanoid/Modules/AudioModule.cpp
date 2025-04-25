#include "AudioModule.h"

#include <SFML/Audio.hpp>

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
	return UPDATE_CONTINUE;
}

bool AudioModule::Close()
{
	return true;
}