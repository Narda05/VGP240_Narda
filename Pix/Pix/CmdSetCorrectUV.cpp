#include "CmdSetCorrectUV.H"
#include "PrimitivesManager.h"
#include "VariableCache.h"

bool CmdSetCorrectUV::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}
	
	bool correctUV = VariableCache::Get()->GetBool(params[0]);
	PrimitivesManager::Get()->SetCorrectUV(correctUV);
	return true;
}