#include "PrimitivesManager.h"
#include "Rasterizer.h"

PrimitivesManager* PrimitivesManager::Get()
{
	static PrimitivesManager sInstance;
	return &sInstance;
}

PrimitivesManager::PrimitivesManager()
{

}

bool PrimitivesManager::BeginDraw(Topology topology)
{
	mTopology = topology;
	mDrawBegin = true;
	mVertexBuffer.clear();
	return true;
}
void PrimitivesManager::AddVertex(const Vertex& vertex)
{
	if (mDrawBegin)
	{
		mVertexBuffer.push_back(vertex);
	}
}

bool PrimitivesManager::EndDraw() //we what to draw somthing 
{
	if (!mDrawBegin)
	{
		return false;
	}

	switch (mTopology)
	{
	case Topology::Point:
	{
		for (size_t i = 0; i < mVertexBuffer.size(); ++i)
		{
			Rasterizer::Get()->DrawPoint(mVertexBuffer[i]);
		}
	}
	break;
	case Topology::Line:
	{
		for (size_t i = 1; i < mVertexBuffer.size(); i += 2)
		{
			Rasterizer::Get()->DrawLine(mVertexBuffer[i - 1], mVertexBuffer[i]);
		}
	}
	break;
	case Topology::Triangle:
	{
		for (size_t i = 2; i < mVertexBuffer.size(); i += 3)
		{
			Rasterizer::Get()->DrawTriangle(mVertexBuffer[i - 2], mVertexBuffer[i - 1], mVertexBuffer[i]);
		}
	}
	break;
	default:
		break;
	}

	mDrawBegin = false;
	return true;
}
