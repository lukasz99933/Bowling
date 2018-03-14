#include <gtest/gtest.h>
#include "bowling.hpp"

using namespace std;

class bowlingTest : public ::testing::Test
{

};


TEST_F(bowlingTest, emptyToken)
{
  Bowling game;
  game.fillTokens("");  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_TRUE(tokens.at(0) == "");
// the question is: should really Tokens be empty? Or maybe they should have one empty string instead...
}


TEST_F(bowlingTest, oneSimpleToken)
{
  Bowling game;
  string s = "a";
  game.fillTokens(s);  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_TRUE(tokens.at(0) == s);
}


TEST_F(bowlingTest, twoEmptyTokens)
{
  Bowling game;
  game.fillTokens("|");  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_TRUE(tokens.at(0) == "");
  ASSERT_TRUE(tokens.at(1) == "");
}

TEST_F(bowlingTest, threeTokens)
{
  Bowling game;
  game.fillTokens("a|grrr|X");  
  auto tokens = game.getTokens();
  ASSERT_TRUE(tokens.at(0) == "a");
  ASSERT_TRUE(tokens.at(1) == "grrr");
  ASSERT_TRUE(tokens.at(2) == "X");
}


TEST_F(bowlingTest, fourTokens)
{
  Bowling game;
  game.fillTokens("a||X|123456");  
  auto tokens = game.getTokens();
  ASSERT_TRUE(tokens.at(0) == "a");
  ASSERT_TRUE(tokens.at(1) == "");
  ASSERT_TRUE(tokens.at(2) == "X");
  ASSERT_TRUE(tokens.at(3) == "123456");
}

TEST_F(bowlingTest, allTokens)
{
  Bowling game;
  game.fillTokens("X|7/|9-|X|-8|8/|-6|X|X|X||81");  
  auto tokens = game.getTokens();
  ASSERT_TRUE(tokens.at(0) == "X");
  ASSERT_TRUE(tokens.at(1) == "7/");
  ASSERT_TRUE(tokens.at(2) == "9-");
  ASSERT_TRUE(tokens.at(3) == "X");
  ASSERT_TRUE(tokens.at(9) == "X");
  ASSERT_TRUE(tokens.at(10) == "81");
}

TEST_F(bowlingTest, validation)
{
    Bowling game;
    game.fillTokens("X|7/|9-|X|-8|8/|-6|X|X|X||81");
    auto tokens = game.getTokens();
    ASSERT_TRUE(game.validateIsCorrect(tokens));

    game.fillTokens("a||X|123456");
    tokens = game.getTokens();
    ASSERT_FALSE(game.validateIsCorrect(tokens));

    game.fillTokens("Y|7/|9-|X|-8|8/|-6|X|X|X||81");
    tokens = game.getTokens();
    ASSERT_FALSE(game.validateIsCorrect(tokens));

}
