#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Update()
{
	position.x += velocity.x;
	position.y += velocity.y;
	position.z = 0.1f * layer;
}

void Entity::Load()
{
	
}

void Entity::LoadTexure(std::string id, std::wstring TexPath)
{
	name = id;
	pathToTex = TexPath;
}

void Entity::SetVelocity(XMFLOAT3 v)
{
	velocity = v;
}

void Entity::SetVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}

void Entity::SetPosition(XMFLOAT3 pos)
{
	position.x = pos.x;
	position.y = pos.y;
	position.z = layer;
}

void Entity::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	position.z = layer;
}

void Entity::SetLayer(float l)
{
	layer = l * 0.1f;
}

void Entity::SetScale(XMFLOAT3 s)
{
	scale = s;
}

void Entity::SetScale(float x, float y, float z)
{
	scale.x = x;
	scale.y = y;
	scale.z = x;
}

XMFLOAT3 Entity::GetScale()
{
	return scale;
}

XMFLOAT3 Entity::GetVelocity()
{
	return velocity;
}

XMFLOAT3 Entity::GetPosition()
{
	return position;
}

std::string Entity::GetTextureName()
{
	return name;
}

std::wstring Entity::GetTexturePath()
{
	return pathToTex;
}
