#include "FilesystemLogger.h"
#include <iostream>

FilesystemLogger::FilesystemLogger(const std::string path)
: out(path, std::ofstream::out)
{
	// empty body
}

void FilesystemLogger::writeInfoEntry(std::string_view entry)
{
	out << "[INFO] " << entry << std::endl;
}

void FilesystemLogger::writeWarnEntry(std::string_view entry)
{
	out << "[WARN] " << entry << std::endl;
}

void FilesystemLogger::writeErrorEntry(std::string_view entry)
{
	out << "[ERROR] " << entry << std::endl;
}
