#include "BG.h"

BG::BG()
{

}

BG::~BG()
{
}

void BG::Load(std::string id, std::wstring TexPath)
{
	SetName(id);
	SetImagePath(TexPath);
	SetScale(100, 100);
	SetPosition(-50, 50);
}

void BG::Update()
{
}
