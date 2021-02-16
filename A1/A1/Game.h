#pragma once
#include "Entity.h"
#include "World.h"
#include <vector>


enum class RenderLayer : int
{
    Opaque = 0,
    AlphaTested,
    Count
};

class Game : public D3DApp
{
public:
    Game(HINSTANCE hInstance);
    Game(const Game& rhs) = delete;
    Game& operator=(const Game& rhs) = delete;
    ~Game();
    virtual bool Initialize()override;
    World GameWorld;
private:
    virtual void OnResize()override;
    virtual void Update(const GameTimer& gt)override;
    virtual void Draw(const GameTimer& gt)override;

    virtual void OnMouseDown(WPARAM btnState, int x, int y)override;
    virtual void OnMouseUp(WPARAM btnState, int x, int y)override;
    virtual void OnMouseMove(WPARAM btnState, int x, int y)override;

    void OnKeyboardInput(const GameTimer& gt);
    void UpdateCamera(const GameTimer& gt);
    void UpdateEntities(const GameTimer& gt);
    void UpdateObjectCBs(const GameTimer& gt);
    void UpdateMaterialCBs(const GameTimer& gt);
    void UpdateMainPassCB(const GameTimer& gt);
    void LoadTextures();
    void BuildRootSignature();
    void BuildDescriptorHeaps();
    void BuildShadersAndInputLayout();
    void BuildShapeGeometry();
    void BuildPSOs();
    void BuildFrameResources();
    void BuildMaterials();
    void BuildEntities();
    void DrawEntities(ID3D12GraphicsCommandList* cmdList, const std::vector<Entity*>& ritems);
    std::array<const CD3DX12_STATIC_SAMPLER_DESC, 6> GetStaticSamplers();

private:
    
    std::vector<std::unique_ptr<FrameResource>> mFrameResources;
    FrameResource* mCurrFrameResource = nullptr;
    int mCurrFrameResourceIndex = 0;
    UINT mCbvSrvDescriptorSize = 0;

    ComPtr<ID3D12RootSignature> mRootSignature = nullptr;

    ComPtr<ID3D12DescriptorHeap> mSrvDescriptorHeap = nullptr;

    //std::unordered_map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;
    //std::unordered_map<std::string, std::unique_ptr<Material>> mMaterials;
    //std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;
    std::unordered_map<std::string, MeshGeometry*> mGeometries;
    std::unordered_map<std::string, Material*> mMaterials;
    std::unordered_map<std::string, Texture*> mTextures;
    

    std::unordered_map<std::string, ComPtr<ID3DBlob>> mShaders;

    std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;


    std::unordered_map<std::string, ComPtr<ID3D12PipelineState>> mPSOs;

    std::vector<Entity*> mRitemLayer[(int)RenderLayer::Count];

    PassConstants mMainPassCB;

    XMFLOAT3 mCamPos = { 0.0f, 0.0f, 0.0f };

    XMFLOAT4X4 mView = MathHelper::Identity4x4();
    XMFLOAT4X4 mProj = MathHelper::Identity4x4();
    
    
    

    POINT mLastMousePos;
};