#include "Knight.h"
#include "Visitor.h"
#include <iostream>

Knight::Knight(std::string name, int x, int y) : name(name), x(x), y(y) {}

std::string Knight::getType() const {
    return "Knight";
}

void Knight::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Knight::fight(NPC& other) {
    // Создаем Visitor для Knight
    class KnightVisitor : public Visitor {
    public:
        void visit(Bandit& bandit) override {
            std::cout << "Knight fights Bandit\n";
        }
        void visit(Knight& knight) override {
            std::cout << "Knight fights Knight\n";
        }
        void visit(Elf& elf) override {
            std::cout << "Knight fights Elf\n";
        }
    };
    KnightVisitor visitor;
    other.accept(visitor);
}

void Knight::print() const {
    std::cout << "Knight " << name << " at (" << x << ", " << y << ")\n";
}

std::string Knight::getName() const {
    return name;
}

int Knight::getX() const {
    return x;
}

int Knight::getY() const {
    return y;
}
