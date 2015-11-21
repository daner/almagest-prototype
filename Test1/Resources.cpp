#include <Windows.h>
#include <iostream>
#include "Resources.h"

std::string resourcesFolder = "Resources\\";

std::string Resources::GetPath(const std::string& fileName)
{
	HMODULE hModule = GetModuleHandleW(NULL);
	WCHAR path[MAX_PATH];
	GetModuleFileNameW(hModule, path, MAX_PATH);
	std::wstring wpath(path);
	std::wstring dir = wpath.substr(0, wpath.find_last_of('\\') + 1);
	return std::string(std::begin(dir), std::end(dir)) + resourcesFolder + fileName;
}