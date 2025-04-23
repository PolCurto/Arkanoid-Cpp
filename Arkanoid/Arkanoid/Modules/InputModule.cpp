#include "InputModule.h"

InputModule::InputModule()
{

}

InputModule::~InputModule()
{

}

bool InputModule::Start()
{
	return true;
}

UpdateState InputModule::Update()
{
	return UPDATE_CONTINUE;
}

bool InputModule::Close()
{
	return true;
}