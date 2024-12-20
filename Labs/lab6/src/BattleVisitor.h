#ifndef BATTLEVISITOR_H
#define BATTLEVISITOR_H

#include "Visitor.h"
#include "Bandit.h"
#include "Knight.h"
#include "Elf.h"

class BattleVisitor : public Visitor {
public:
    void visit(Bandit& bandit) override;
    void visit(Knight& knight) override;
    void visit(Elf& elf) override;
};

#endif // BATTLEVISITOR_H
