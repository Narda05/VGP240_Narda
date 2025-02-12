#include "CmdVarBool.h"
#include "VariableCache.h"

bool CmdVarBool::Execute(const std::vector<std::string>& params)
{
	// need at least 3 params name, =, value 
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	if (!vc->IsVarName(params[0]) || params[1] != "=")
	{
		return false;
	}

	const bool value = params[2] == "true";
	//register the variable
	vc->AddBool(params[0], value);
	return true;
}