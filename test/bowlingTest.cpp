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
  ASSERT_FALSE(game.getTokens().empty());
  ASSERT_TRUE(game.getTokens()[0] == "");
// the question is: should really Tokens be empty? Or maybe they should have one empty string instead...
}


TEST_F(bowlingTest, oneSimpleToken)
{
  Bowling game;
  string s = "a";
  game.fillTokens(s);  
  ASSERT_FALSE(game.getTokens().empty());
  ASSERT_TRUE(game.getTokens()[0] == s);
}


TEST_F(bowlingTest, twoEmptyTokens)
{
  Bowling game;
  string s = "|";
  game.fillTokens(s);  
  ASSERT_FALSE(game.getTokens().empty());
  ASSERT_TRUE(game.getTokens()[0] == "");
  ASSERT_TRUE(game.getTokens()[1] == "");
}

TEST_F(bowlingTest, threeTokens)
{
  Bowling game;
  string s = "a|grrr|X";
  game.fillTokens(s);  
  ASSERT_FALSE(game.getTokens().empty());
  ASSERT_TRUE(game.getTokens()[0] == "a");
  ASSERT_TRUE(game.getTokens()[1] == "grrr");
  ASSERT_TRUE(game.getTokens()[2] == "X");
}

