#include "World.h"

World::World()
{

}

World::~World()
{
}

void World::Load()
{
	for (int i = 0; i < 3; i++)
	{
		aircrafts[i] = new Entity;
		std::string name = std::to_string(i) + "planeTex";
		aircrafts[i]->LoadTexure(name, L"../../Textures/plane.dds");
		aircrafts[i]->SetScale(2, 2, 2);
		aircrafts[i]->SetVelocity(0, 5);
		AddEntity(aircrafts[i]);
	}

	aircrafts[0]->SetPosition(0, 0);
	aircrafts[1]->SetPosition(aircrafts[0]->GetPosition().x - 3, aircrafts[0]->GetPosition().y - 3);
	aircrafts[2]->SetPosition(aircrafts[0]->GetPosition().x + 3, aircrafts[0]->GetPosition().y - 3);

	bg = new Entity;
	bg->LoadTexure("grassTex", L"../../Textures/grass.dds");
	bg->SetScale(100, 100, 100);
	bg->SetLayer(-1);
	bg->SetPosition(-50, 50);
	AddEntity(bg);
}

void World::Update(const GameTimer& gt)
{
	for (int i = 0; i < entities.size(); i++)
	{
		GetEntity(i)->Update();
	}
}

void World::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}

Entity* World::GetEntity(int i)
{
	return entities[i];
}

std::vector<Entity*> World::GetEntities()
{
	return entities;
}

