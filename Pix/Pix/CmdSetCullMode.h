#pragma once

#include"Command.h"

class CmdSetCullMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetCullMode";
	}

	const char* GetDescription() override
	{
		return
			"SetCullMode(mode)"
			"\n"
			"- none will not use any face culing"
			"- back will not render anythig facing away from the camera"
			"'- front will not render anything facing the camera";
	}
	bool Execute(const std::vector<std::string>& params) override;

};
