#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Filesystem.h"

std::string Filesystem::GetPath(const std::string& fileName)
{
	WCHAR path[MAX_PATH];
	GetModuleFileNameW(nullptr, path, MAX_PATH);
	std::wstring wpath(path);
	auto dir = wpath.substr(0, wpath.find_last_of('\\') + 1);
	return std::string(begin(dir), end(dir)) + fileName;
}

std::string Filesystem::GetFileContent(const std::string& fileName)
{
		std::string result;
		std::ifstream file(fileName.c_str());	
		file.seekg(0, std::ios::end);
		result.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		result.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
		return result;	
}