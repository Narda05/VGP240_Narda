#include "Graphics.h"

#include "Viewport.h"
#include "Clipper.h"
#include "MatrixStack.h"
#include "Camera.h"
#include "PrimitivesManager.h"
#include "DepthBuffer.h"
#include "MaterialManager.h"
#include "LightManager.h"
#include "PostProcessing.h"

void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
	Camera::Get()->OnNewFrame();
	PrimitivesManager::Get()->OnNewFrame();
	DepthBuffer::Get()->OnNewFrame();
	MaterialManager::Get()->OnNewFrame();
	LightManager::Get()->OnNewFrame();
	PostProcessing::Get()->OnNewFrame();
}