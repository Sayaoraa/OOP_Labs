#include "Elf.h"
#include "Visitor.h"
#include <iostream>

Elf::Elf(std::string name, int x, int y) : name(name), x(x), y(y) {}

std::string Elf::getType() const {
    return "Elf";
}

void Elf::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Elf::fight(NPC& other) {
    // Создаем Visitor для Elf
    class ElfVisitor : public Visitor {
    public:
        void visit(Bandit& bandit) override {
            std::cout << "Elf fights Bandit\n";
        }
        void visit(Knight& knight) override {
            std::cout << "Elf fights Knight\n";
        }
        void visit(Elf& elf) override {
            std::cout << "Elf fights Elf\n";
        }
    };
    ElfVisitor visitor;
    other.accept(visitor);
}

void Elf::print() const {
    std::cout << "Elf " << name << " at (" << x << ", " << y << ")\n";
}

std::string Elf::getName() const {
    return name;
}

int Elf::getX() const {
    return x;
}

int Elf::getY() const {
    return y;
}
