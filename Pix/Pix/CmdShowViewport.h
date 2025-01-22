#pragma once
#include "command.h"


class CmdShowViewport : public Command
{
public:
	const char* GetName() override
	{
		return "showviewport";
	}
	const char* GetDescription() override
	{
		return 
			"Show the viewport"
			"\n"
			"- show or hides yhe viewport";
	}
	bool Execute(const std::vector<std::string>& params) override;
};