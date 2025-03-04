#pragma once

#include "Command.h"

class CmdSetShadeMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetShadeMode";
	}
	const char* GetDescription() override
	{
		return
			"SetShadeMode(shadeMode)"
			"\n"
			"-flat, gouraud, phong";
	}
	bool Execute(const std::vector<std::string>& args) override;
};
