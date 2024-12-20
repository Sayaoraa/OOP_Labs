#ifndef ELF_H
#define ELF_H

#include "NPC.h"
#include <string>

class Elf : public NPC {
public:
    Elf(std::string name, int x, int y);
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

#endif // ELF_H
