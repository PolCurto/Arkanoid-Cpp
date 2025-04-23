#include "GameModule.h"

GameModule::GameModule()
{

}

GameModule::~GameModule()
{

}

bool GameModule::Start()
{
	return true;
}

UpdateState GameModule::Update()
{
	return UPDATE_CONTINUE;
}

bool GameModule::Close()
{
	return true;
}