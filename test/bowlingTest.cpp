#include <gtest/gtest.h>
#include "bowling.hpp"

using namespace std;

class bowlingTest : public ::testing::Test
{

};

TEST_F(bowlingTest, skeleton)
{
  ASSERT_TRUE(true);
}

TEST_F(bowlingTest, emptyTokens)
{
  Bowling game;
  game.fillTokens("");  
  ASSERT_TRUE(game.getTokens().empty());
}

