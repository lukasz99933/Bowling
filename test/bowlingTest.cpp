#include <gtest/gtest.h>
#include "bowling.hpp"

using namespace std;

class bowlingTest : public ::testing::Test
{

};


TEST_F(bowlingTest, emptyTokens)
{
  Bowling game;
  game.fillTokens("");  
  ASSERT_TRUE(game.getTokens().empty());
}


TEST_F(bowlingTest, oneSimpleToken)
{
  Bowling game;
  string s = " ";
  game.fillTokens(s);  
  ASSERT_FALSE(game.getTokens().empty());
  ASSERT_TRUE(game.getTokens()[0] == s);
}

