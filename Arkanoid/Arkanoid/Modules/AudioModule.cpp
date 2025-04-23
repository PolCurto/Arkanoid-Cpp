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

UpdateState AudioModule::Update()
{
	return UPDATE_CONTINUE;
}

bool AudioModule::Close()
{
	return true;
}