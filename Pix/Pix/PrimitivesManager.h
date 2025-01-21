#pragma once
#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

class PrimitivesManager
{
	//everyone has access
public:
	static PrimitivesManager* Get();

	bool BeginDraw(Topology topology);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();


	//only this class can see
private:
	PrimitivesManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	bool mDrawBegin = false;

};