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
		aircrafts[i] = new Aircraft();
		aircrafts[i]->SetName(std::to_string(i) + "plane");
		aircrafts[i]->Load(aircrafts[i]->GetName(), L"../../Textures/plane.dds");
		AddEntity(std::move(aircrafts[i]));
	}

	aircrafts[0]->SetPosition(0, 0);
	aircrafts[1]->SetPosition(aircrafts[0]->GetPosition3f().x - 3, aircrafts[0]->GetPosition3f().y - 3);
	aircrafts[2]->SetPosition(aircrafts[0]->GetPosition3f().x + 3, aircrafts[0]->GetPosition3f().y - 3);

	bg = new BG;
	bg->Load("grassTex", L"../../Textures/grass.dds");

	AddEntity(std::move(bg));
}

void World::Update(const GameTimer& gt)
{
	for (int i = 0; i < 3; i++)
	{
		aircrafts[i]->Update();
	}
}

void World::AddEntity(Entity* e)
{
	entities.push_back(e);
}

Entity* World::GetEntity(int i)
{
	return entities[i];
}

std::vector<Entity*> World::GetEntities()
{
	return entities;
}