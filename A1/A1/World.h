#pragma once
#include "Entity.h"

class World
{
public:
	World();
	~World();
	void Load(); 
	void Update(const GameTimer& gt);
	void AddEntity(Entity* entity);
	Entity* GetEntity(int i);
	std::vector<Entity*> GetEntities();
private:
	std::vector<Entity*> entities;
	Entity* aircrafts[3];
	Entity* bg;
};

