#include "StandardOutputLogger.h"
#include <iostream>

void StandardOutputLogger::writeInfoEntry(std::string_view entry)
{
	std::cout << "[INFO] " << entry << std::endl;
}

void StandardOutputLogger::writeWarnEntry(std::string_view entry)
{
	std::cout << "[WARN] " << entry << std::endl;
}

void StandardOutputLogger::writeErrorEntry(std::string_view entry)
{
	std::cout << "[ERROR] " << entry << std::endl;
}
