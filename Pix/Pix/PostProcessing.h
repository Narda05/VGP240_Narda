#pragma once

#include "RenderTarget.h"

enum class EffectType
{
	None, 
	MonoChrome,
	Invert,
	Mirror,
	Blur,
	ColorMaskR,
	ColorMaskG,
	ColorMaskB,
	Sepia,
	Wave,
	FishEye
};

class PostProcessing
{
public:
	static PostProcessing* Get();

	void Initialize(int width, int height, const X::Color& clearColor = X::Colors::Black);
	void OnNewFrame();
	void SetEffectType(EffectType effectType);

	void BeginDraw();
	bool Draw(int x, int y, const X::Color& color);
	void EndDraw();

private:
	void DrawPixel(int x, int y);

	bool mDrawBegin = false;
	X::Color mClearColor = X::Colors::Black;
	RenderTarget mRenderTarget;
	EffectType mEffectType = EffectType::None;
}; 