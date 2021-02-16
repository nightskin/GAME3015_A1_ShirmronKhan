#pragma once
#pragma once
#include "Entity.h"

class BG : public Entity
{
public:
	BG();
	~BG();
	void Load(std::string id, std::wstring TexPath) override;
	void Update() override;
private:

};
