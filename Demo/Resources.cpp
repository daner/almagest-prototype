#include <Windows.h>
#include <iostream>
#include "Resources.h"

std::string resourcesFolder = "Resources\\";

std::string Resources::GetPath(const std::string& fileName)
{
	WCHAR path[MAX_PATH];
	GetModuleFileNameW(nullptr, path, MAX_PATH);
	std::wstring wpath(path);
	auto dir = wpath.substr(0, wpath.find_last_of('\\') + 1);
	return std::string(begin(dir), end(dir)) + resourcesFolder + fileName;
}