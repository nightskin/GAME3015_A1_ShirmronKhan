#pragma once
#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "../../Common/GeometryGenerator.h"
#include "FrameResource.h"
#include <string>

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

class Entity
{
public:
	Entity();
	~Entity();
	virtual void Update();
	virtual void Load();
	void LoadTexure(std::string id, std::wstring TexPath);
	void SetVelocity(XMFLOAT3 v);
	void SetVelocity(float x, float y);
	void SetPosition(XMFLOAT3 pos);
	void SetPosition(float x, float y);
	void SetLayer(float l);

	void SetScale(XMFLOAT3 s);
	void SetScale(float x, float y, float z);

	XMFLOAT3 GetScale();
	XMFLOAT3 GetVelocity();
	XMFLOAT3 GetPosition();
	std::string GetTextureName();
	std::wstring GetTexturePath();

private:
	float layer = 0;
	std::string name;
	std::wstring pathToTex;
	XMFLOAT3 velocity;
	XMFLOAT3 position;
	XMFLOAT3 scale;
};
