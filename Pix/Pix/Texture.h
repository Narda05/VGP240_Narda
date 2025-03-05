#pragma once
#include <XEngine.h>


class Texture
{
public:
	void Load(const std::string& fileName);
	const std::string& GetFileName() const;

	// u and v are 0-1
	X::Color GetPixel(float u, float v) const;

	int GetWidth() const;
	int GetHeight() const;
private: 
	//texel coordinates
	X::Color GetPixel(int u, int v) const;
	
std::string mFileName;
	std::unique_ptr<X::Color[]> mPixels;
	int mWidth = 0;
	int mHeight = 0;
};