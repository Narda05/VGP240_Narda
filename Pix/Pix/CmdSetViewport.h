#pragma once


#include "Command.h"

class CmdSetViewport : public Command
{
public:
	const char* GetName() override
	{
		return "setviewport";
	}

	const char* GetDescription() override
	{
		return "Set the viewport size";
	}

	bool Execute(const std::vector<std::string>& params) override;


};