#include <gtest/gtest.h>
#include "NPCFactory.h"
#include "BattleVisitor.h"
#include "FileObserver.h"
#include "ConsoleObserver.h"

TEST(NPCFactoryTest, CreateBandit) {
    auto bandit = NPCFactory::createNPC("Bandit", "Bandit1", 100, 100);
    ASSERT_EQ(bandit->getType(), "Bandit");
    ASSERT_EQ(bandit->getName(), "Bandit1");
    ASSERT_EQ(bandit->getX(), 100);
    ASSERT_EQ(bandit->getY(), 100);
}

TEST(NPCFactoryTest, CreateKnight) {
    auto knight = NPCFactory::createNPC("Knight", "Knight1", 200, 200);
    ASSERT_EQ(knight->getType(), "Knight");
    ASSERT_EQ(knight->getName(), "Knight1");
    ASSERT_EQ(knight->getX(), 200);
    ASSERT_EQ(knight->getY(), 200);
}

TEST(NPCFactoryTest, CreateElf) {
    auto elf = NPCFactory::createNPC("Elf", "Elf1", 300, 300);
    ASSERT_EQ(elf->getType(), "Elf");
    ASSERT_EQ(elf->getName(), "Elf1");
    ASSERT_EQ(elf->getX(), 300);
    ASSERT_EQ(elf->getY(), 300);
}

TEST(BattleVisitorTest, VisitBandit) {
    auto bandit = NPCFactory::createNPC("Bandit", "Bandit1", 100, 100);
    BattleVisitor visitor;
    bandit->accept(visitor);
    // Добавьте проверки для посещения
}

TEST(BattleVisitorTest, VisitKnight) {
    auto knight = NPCFactory::createNPC("Knight", "Knight1", 200, 200);
    BattleVisitor visitor;
    knight->accept(visitor);
    // Добавьте проверки для посещения
}

TEST(BattleVisitorTest, VisitElf) {
    auto elf = NPCFactory::createNPC("Elf", "Elf1", 300, 300);
    BattleVisitor visitor;
    elf->accept(visitor);
    // Добавьте проверки для посещения
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
