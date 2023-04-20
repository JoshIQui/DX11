#pragma once
#include <d3d11.h>
#include <wrl/client.h>
#include "DXCore.h"

#include "Camera.h"
#include "GameEntity.h"
#include "Lights.h"
#include "Sky.h"
#include "Mesh.h"

class Renderer
{

public:
	Renderer(
		Microsoft::WRL::ComPtr<ID3D11Device> device,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> context,
		Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain,
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> backBufferRTV,
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthBufferDSV,
		unsigned int windowWidth,
		unsigned int windowHeight
	);

	~Renderer();

	void PreResize();

	void PostResize(
		unsigned int windowWidth, 
		unsigned int windowHeight, 
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> backBufferRTV,
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthBufferDSV
	);

	void FrameStart();

	void FrameEnd(bool vsync, bool deviceSupportsTearing, bool isFullscreen);

	void RenderScene(
		std::shared_ptr<SimpleVertexShader> lightVS,
		std::shared_ptr<SimplePixelShader> lightPS,
		std::shared_ptr<Camera> camera,
		const std::vector<std::shared_ptr<GameEntity>> entities,
		const std::vector<Light> lights,
		std::shared_ptr<Mesh> lightMesh,
		std::shared_ptr<Sky> sky,
		bool showPointLights,
		int lightCount,
		bool vsync,
		bool deviceSupportsTearing,
		bool isFullscreen
	);

	void DrawPointLights(
		std::shared_ptr<SimpleVertexShader> lightVS,
		std::shared_ptr<SimplePixelShader> lightPS,
		std::shared_ptr<Camera> camera,
		const std::vector<Light> lights,
		std::shared_ptr<Mesh> lightMesh,
		int lightCount
	);

private:
	Microsoft::WRL::ComPtr<ID3D11Device> device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> context;
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;

	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> backBufferRTV;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthBufferDSV;

	unsigned int windowWidth;
	unsigned int windowHeight;
};

