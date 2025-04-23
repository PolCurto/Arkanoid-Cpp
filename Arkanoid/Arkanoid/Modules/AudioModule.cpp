#include "AudioModule.h"

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

UpdateState AudioModule::Update(const float deltaTime)
{
	return UPDATE_CONTINUE;
}

bool AudioModule::Close()
{
	return true;
}