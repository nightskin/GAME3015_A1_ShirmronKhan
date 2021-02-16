#pragma once
#include "Entity.h"
class Aircraft: public Entity
{
public:
	Aircraft();
	~Aircraft();
	void Load(std::string id, std::wstring TexPath) override;
	void Update() override;
private:

};
