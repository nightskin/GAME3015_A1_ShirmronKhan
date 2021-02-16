#pragma once
#include "Entity.h"
#include "Aircraft.h"
#include "BG.h"

class World
{
public:
	World();
	~World();
	void Load(); 
	void Update(const GameTimer& gt);
	void AddEntity(Entity* e);
	Entity* GetEntity(int i);
	std::vector<Entity*> GetEntities();
	
private:
	std::vector<Entity*> entities;
	Aircraft* aircrafts[3];
	BG* bg;
	//std::vector<std::unique_ptr<Entity>> entities;
	//std::unique_ptr<BG> bg;
	//std::unique_ptr<Aircraft> aircrafts[3];
};

