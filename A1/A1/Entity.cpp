#include "Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Update()
{
	position3f.x += velocity3f.x;
	position3f.y += velocity3f.y;
}

void Entity::Load(std::string id, std::wstring TexPath)
{
	name = id;
	pathToTex = TexPath;
}

void Entity::SetVelocity(XMFLOAT3 v)
{
	velocity3f = v;
}

void Entity::SetVelocity(float x, float y)
{
	velocity3f.x = x;
	velocity3f.y = y;
	velocity3f.z = 0;
}

void Entity::SetPosition(XMFLOAT3 pos)
{
	position3f.x = pos.x;
	position3f.y = pos.y;
	position3f.z = layer;
}

void Entity::SetPosition(float x, float y)
{
	position3f.x = x;
	position3f.y = y;
	position3f.z = layer;
}

void Entity::SetLayer(float l)
{
	layer = l;
}

void Entity::SetScale(XMFLOAT3 s)
{
	scale3f = s;
	scale3f.z = 1;
}

void Entity::SetScale(float x, float y)
{
	scale3f.x = x;
	scale3f.y = y;
	scale3f.z = 1;
}

void Entity::SetName(std::string id)
{
	name = id;
}

void Entity::SetImagePath(std::wstring path)
{
	pathToTex = path;
}

XMFLOAT3 Entity::GetScale3f()
{
	return scale3f;
}

XMFLOAT3 Entity::GetVelocity3f()
{
	return velocity3f;
}

XMFLOAT3 Entity::GetPosition3f()
{
	return position3f;
}

std::string Entity::GetName()
{
	return name;
}

std::wstring Entity::GetImagePath()
{
	return pathToTex;
}
