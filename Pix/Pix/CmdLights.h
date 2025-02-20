#pragma once

#include "Command.h"

class CmdSetLightAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightAmbient";
	}
	const char* GetDescription()
	{
		return "SetLightAmbient(r, g, b)"
			"\n"
			"- sets the ambient color for the light";
	}
	bool Execute(const std::vector<std::string>& params) override;
};


class CmdSetLightDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightDiffuse";
	}
	const char* GetDescription()
	{
		return "SetLightDiffuse(r, g, b)"
			"\n"
			"- sets the Diffuse color for the light";
	}
	bool Execute(const std::vector<std::string>& params) override;
};


class CmdSetLightSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightSpecular";
	}
	const char* GetDescription()
	{
		return "SetLightSpecular(r, g, b)"
			"\n"
			"- sets the Specular color for the light";
	}
	bool Execute(const std::vector<std::string>& params) override;
};


class CmdAddDirectionalLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddDirectionalLight";
	}
	const char* GetDescription()
	{
		return "AddDirectionalLight(x, y, z)"
			"\n"
			"- add a directional light to the scene.";
	}
	bool Execute(const std::vector<std::string>& params) override;
};