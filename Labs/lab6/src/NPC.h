#ifndef NPC_H
#define NPC_H

#include <string>

class Visitor;

class NPC {
public:
    virtual ~NPC() = default;
    virtual std::string getType() const = 0;
    virtual void accept(Visitor& visitor) = 0;
    virtual void fight(NPC& other) = 0;
    virtual void print() const = 0;
    virtual std::string getName() const = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
};

#endif // NPC_H
