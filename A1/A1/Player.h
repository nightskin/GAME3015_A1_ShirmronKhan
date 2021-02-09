#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();
	void Load() override;
	void Update() override;
private:

};

