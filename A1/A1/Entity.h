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
	virtual void Load(std::string id, std::wstring TexPath);
	void SetVelocity(XMFLOAT3 v);
	void SetVelocity(float x, float y);
	void SetPosition(XMFLOAT3 pos);
	void SetPosition(float x, float y);
	
	void SetLayer(float l);
	void SetName(std::string id);
	void SetImagePath(std::wstring path);

	void SetScale(XMFLOAT3 s);
	void SetScale(float x, float y);

	XMFLOAT3 GetScale3f();
	XMFLOAT3 GetVelocity3f();
	XMFLOAT3 GetPosition3f();

	std::string GetName();
	std::wstring GetImagePath();

public:
	XMFLOAT4X4 WorldSpace = MathHelper::Identity4x4();
	XMFLOAT4X4 TexTransform = MathHelper::Identity4x4();
	int NumFramesDirty = gNumFrameResources;
	UINT ObjCBIndex = -1;
	Material* Mat = nullptr;
	MeshGeometry* Geo = nullptr;
	D3D12_PRIMITIVE_TOPOLOGY PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	UINT IndexCount = 0;
	UINT StartIndexLocation = 0;
	int BaseVertexLocation = 0;
private:
	float layer = 0;
	std::string name;
	std::wstring pathToTex;
	XMFLOAT3 velocity3f;
	XMFLOAT3 position3f;
	XMFLOAT3 scale3f;

	XMVECTOR velocity;
	XMVECTOR position;
	XMVECTOR scale;
};
