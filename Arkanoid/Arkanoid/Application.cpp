#include "Application.h"

Application::Application()
{

}

Application::~Application()
{

}

bool Application::Start()
{
	return true;
}

UpdateState Application::Update()
{
	return UPDATE_CONTINUE;
}

bool Application::Close()
{
	return true;
}