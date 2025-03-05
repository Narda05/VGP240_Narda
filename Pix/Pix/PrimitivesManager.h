#pragma once
#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None, // no face culling 
	Back, //cull items facing away from camera
	Front // cull items facing towards the camera
};

class PrimitivesManager
{
	//everyone has access
public:
	static PrimitivesManager* Get();

	void OnNewFrame(); 
	void SetCullMode(CullMode mode);
	void SetCorrectUV(bool correctUV);

	bool BeginDraw(Topology topology, bool applyTransform = false);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();


	//only this class can see
private:
	PrimitivesManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	CullMode mCullMode = CullMode::Back;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
	bool mCorrectUV = false;

};