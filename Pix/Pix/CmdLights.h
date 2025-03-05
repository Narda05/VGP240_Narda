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
	const char* GetDescription() override
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
	const char* GetDescription() override
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
	const char* GetDescription() override
	{
		return "AddDirectionalLight(x, y, z)"
			"\n"
			"- add a directional light to the scene.";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdAddPointLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddPointLight";
	}
	const char* GetDescription() override
	{
		return "AddPointLight(x, y, z, <constant>, <linear>, <quadratic>)\n"
			"\n"
			"- add a point light to the light manager.";
	}
	bool Execute(const std::vector<std::string>& params) override;

};

class CmdAddSpotLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddSpotLight";
	}
	const char* GetDescription() override
	{
		return "AddPointLight(pX, pY, pZ, dX, dY, dZ, <constant>, <linear>, <quadratic>, <angle>, <decay>"
			"\n"
			"- add a spot light to the light manager.";
	}
	bool Execute(const std::vector<std::string>& params) override;
};