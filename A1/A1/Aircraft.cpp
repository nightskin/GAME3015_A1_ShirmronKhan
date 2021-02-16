#include "Aircraft.h"

Aircraft::Aircraft()
{
}

Aircraft::~Aircraft()
{
}

void Aircraft::Load(std::string id, std::wstring TexPath)
{
	SetName(id);
	SetImagePath(TexPath);
	SetScale(2, 2);
	SetVelocity(0, 1);
}

void Aircraft::Update()
{
	
}
