#include "RenderModule.h"

RenderModule::RenderModule()
{

}

RenderModule::~RenderModule()
{

}

bool RenderModule::Start()
{
	return true;
}

UpdateState RenderModule::Update()
{
	return UPDATE_CONTINUE;
}

bool RenderModule::Close()
{
	return true;
}