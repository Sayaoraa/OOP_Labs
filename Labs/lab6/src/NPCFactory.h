#ifndef NPCFACTORY_H
#define NPCFACTORY_H

#include <memory>
#include <string>
#include "NPC.h"

class NPCFactory {
public:
    static std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y);
};

#endif // NPCFACTORY_H
