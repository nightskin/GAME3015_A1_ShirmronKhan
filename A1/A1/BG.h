#pragma once
#pragma once
#include "Entity.h"

class BG : public Entity
{
public:
	BG();
	~BG();
	void Load() override;
	void Update() override;
private:

};
