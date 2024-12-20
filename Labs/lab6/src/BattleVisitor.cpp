#include "BattleVisitor.h"
#include <iostream>

void BattleVisitor::visit(Bandit& bandit) {
    // Логика сражения для Разбойника
    std::cout << "Bandit " << bandit.getName() << " is fighting.\n";
}

void BattleVisitor::visit(Knight& knight) {
    // Логика сражения для Рыцаря
    std::cout << "Knight " << knight.getName() << " is fighting.\n";
}

void BattleVisitor::visit(Elf& elf) {
    // Логика сражения для Эльфа
    std::cout << "Elf " << elf.getName() << " is fighting.\n";
}
