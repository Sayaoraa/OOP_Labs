#ifndef BANDIT_H
#define BANDIT_H

#include "NPC.h"
#include <string>

class Bandit : public NPC {
public:
    Bandit(std::string name, int x, int y);
    std::string getType() const override;
    void accept(Visitor& visitor) override;
    void fight(NPC& other) override;
    void print() const override;
    std::string getName() const override;
    int getX() const override;
    int getY() const override;
private:
    std::string name;
    int x, y;
};

#endif // BANDIT_H
