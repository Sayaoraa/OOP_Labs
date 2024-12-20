#include "NPCFactory.h"
#include "Bandit.h"
#include "Knight.h"
#include "Elf.h"
#include <stdexcept>

std::unique_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Bandit") {
        return std::make_unique<Bandit>(name, x, y);
    } else if (type == "Knight") {
        return std::make_unique<Knight>(name, x, y);
    } else if (type == "Elf") {
        return std::make_unique<Elf>(name, x, y);
    }
    throw std::invalid_argument("Unknown NPC type");
}
