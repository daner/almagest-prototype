#pragma once
#include <string>
#include <map>

class Shader
{
public:
	Shader(std::string vertexFilename, std::string fragmentFilename);
	~Shader();

	Shader() = delete;

	Shader(const Shader &other) = delete;
	Shader &operator=(const Shader &other) = delete;

	Shader(Shader &&other);
	Shader &operator=(Shader &&other);

	void Use();

private:
	void LoadShader();
	void UnloadShader();
	void CacheUniformVariables();

	std::string vertexFilename;
	std::string fragmentFilename;

	int programId;
	int vertexShaderId;
	int fragmentShaderId;

	std::map<std::string, int> uniformLocations;
};