#include "Shader.h"
#include "../Filesystem.h"

Shader::Shader(std::string vertexFilename, std::string fragmentFilename) : 
	vertexFilename(vertexFilename), 
	fragmentFilename(fragmentFilename), 
	programId(0), 
	vertexShaderId(0), 
	fragmentShaderId(0)
{
	LoadShader();
}

Shader::~Shader()
{
	if(programId != 0)
	{
		UnloadShader();
	}
}

Shader::Shader(Shader&& other) :
	vertexFilename(other.vertexFilename),
	fragmentFilename(other.fragmentFilename),
	programId(other.programId),
	vertexShaderId(other.vertexShaderId),
	fragmentShaderId(other.fragmentShaderId)
{
	other.programId = 0;
	other.vertexShaderId = 0;
	other.fragmentShaderId = 0;
}

Shader& Shader::operator=(Shader&& other)
{
	vertexFilename = other.vertexFilename;
	fragmentFilename = other.fragmentFilename;
	programId = other.programId;
	vertexShaderId = other.vertexShaderId;
	fragmentShaderId = other.fragmentShaderId;
	other.programId = 0;
	other.vertexShaderId = 0;
	other.fragmentShaderId = 0;
	return *this;
}

void Shader::Use()
{
}

void Shader::LoadShader()
{
	auto vertexSource = Filesystem::GetFileContents(Filesystem::GetPath("Resoruces/Shaders/" + vertexFilename));
	auto fragmentSource = Filesystem::GetFileContents(Filesystem::GetPath("Resoruces/Shaders/" + fragmentFilename));

}

void Shader::UnloadShader()
{
}

void Shader::CacheUniformVariables()
{
}