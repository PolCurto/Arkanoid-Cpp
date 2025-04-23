#include "Block.h"

Block::Block() : Entity(EntityType::Block)
{

}

Block::~Block()
{

}

bool Block::Start()
{
	return true;
}

UpdateState Block::Update()
{
	return UPDATE_CONTINUE;
}

bool Block::Close()
{
	return true;
}