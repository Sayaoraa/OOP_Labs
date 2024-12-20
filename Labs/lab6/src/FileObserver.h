#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "Observer.h"
#include <fstream>

class FileObserver : public Observer {
public:
    void update(const std::string& message) override;
};

#endif // FILEOBSERVER_H
