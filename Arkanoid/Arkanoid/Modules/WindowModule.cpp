#include "WindowModule.h"

WindowModule::WindowModule()
{

}

WindowModule::~WindowModule()
{

}

bool WindowModule::Start()
{
	return true;
}

UpdateState WindowModule::Update()
{
	return UPDATE_CONTINUE;
}

bool WindowModule::Close()
{
	return true;
}