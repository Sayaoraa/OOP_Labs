#include "Bandit.h"
#include "Visitor.h"
#include <iostream>

Bandit::Bandit(std::string name, int x, int y) : name(name), x(x), y(y) {}

std::string Bandit::getType() const {
    return "Bandit";
}

void Bandit::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Bandit::fight(NPC& other) {
    // Создаем Visitor для Bandit
    class BanditVisitor : public Visitor {
    public:
        void visit(Bandit& bandit) override {
            std::cout << "Bandit fights Bandit\n";
        }
        void visit(Knight& knight) override {
            std::cout << "Bandit fights Knight\n";
        }
        void visit(Elf& elf) override {
            std::cout << "Bandit fights Elf\n";
        }
    };
    BanditVisitor visitor;
    other.accept(visitor);
}

void Bandit::print() const {
    std::cout << "Bandit " << name << " at (" << x << ", " << y << ")\n";
}

std::string Bandit::getName() const {
    return name;
}

int Bandit::getX() const {
    return x;
}

int Bandit::getY() const {
    return y;
}
