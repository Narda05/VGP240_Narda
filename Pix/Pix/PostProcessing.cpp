#include "PostProcessing.h"

PostProcessing* PostProcessing::Get()
{
	static PostProcessing sInstance;
	return &sInstance;
}

void PostProcessing::Initialize(int width, int height, const X::Color& clearColor)
{
	mClearColor = clearColor;
	mRenderTarget.Initialize(width, height, clearColor);
}
void PostProcessing::OnNewFrame()
{
	mDrawBegin = false;
	mEffectType = EffectType::None;
	
}
void PostProcessing::SetEffectType(EffectType effectType)
{
	mEffectType = effectType;
}
void PostProcessing::BeginDraw()
{
	mDrawBegin = true;
	if (mDrawBegin)
	{
		mRenderTarget.ClearImage(mClearColor);
	}
}
bool PostProcessing::Draw(int x, int y, const X::Color& color)
{
	if (mDrawBegin)
	{
		mRenderTarget.DrawPixel(x, y, color);
		return true;
	}
	return false;
}
void PostProcessing::EndDraw()
{
	if (mDrawBegin)
	{
		for (int y = 0; y < mRenderTarget.GetHeight(); ++y)
		{
			for (int x = 0; x < mRenderTarget.GetWidth(); ++x)
			{
				DrawPixel(x, y);
			}
		}
	}
	mDrawBegin = false;
}

void PostProcessing::DrawPixel(int x, int y)
{
	X::Color color = mRenderTarget.GetColor(x, y);
	X::DrawPixel(x, y, color);
}