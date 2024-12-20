#ifndef VISITOR_H
#define VISITOR_H

class Bandit;
class Knight;
class Elf;

class Visitor {
public:
    virtual void visit(Bandit& bandit) = 0;
    virtual void visit(Knight& knight) = 0;
    virtual void visit(Elf& elf) = 0;
};

#endif // VISITOR_H
