#include "FileObserver.h"

void FileObserver::update(const std::string& message) {
    std::ofstream logFile("log.txt", std::ios::app);
    logFile << message << std::endl;
}
