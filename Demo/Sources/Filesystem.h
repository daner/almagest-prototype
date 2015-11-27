#pragma once
#include <string>

class Filesystem {
public:
	static std::string GetPath(const std::string& fileName);
	static std::string GetFileContents(const std::string& fileName);
};