#pragma once
#include <map>

class ShaderFactory
{
public:
	ShaderFactory(void);
	~ShaderFactory(void);

	void Initialize();

	void BuildTestShader();

private:
	std::map<int, std::string> helperFunctions;

	static const int TEXTURES = 0x0001;
	static const int DIFFUSETEX = 0x0002;
	static const int NORMALS = 0x0004;
	static const int TANGENT = 0x0008;
	static const int DISPLACEMENTMAP = 0x00010;
	static const int NORMALMAP = 0x00020;
	static const int AMBIENTOCCLUSIONMAP = 0x00040;
	static const int LIGHTMAP = 0x00080;
	static const int BESPOKE = 0x80000;
};

