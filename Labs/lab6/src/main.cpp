#include <iostream>
#include <vector>
#include <memory>
#include "NPCFactory.h"
#include "BattleVisitor.h"
#include "FileObserver.h"
#include "ConsoleObserver.h"

int main() {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Bandit", "Bandit1", 100, 100));
    npcs.push_back(NPCFactory::createNPC("Knight", "Knight1", 200, 200));
    npcs.push_back(NPCFactory::createNPC("Elf", "Elf1", 300, 300));

    // Пример печати NPC
    for (const auto& npc : npcs) {
        npc->print();
    }

    // Пример сражения
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = 0; j < npcs.size(); ++j) {
            if (i != j) {
                npcs[i]->fight(*npcs[j]);
            }
        }
    }

    return 0;
}
