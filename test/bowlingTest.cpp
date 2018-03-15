#include <gtest/gtest.h>
#include "bowling.hpp"

using namespace std;

class bowlingTest : public ::testing::Test
{
public:
  Bowling game;
};


TEST_F(bowlingTest, emptyToken)
{
  game.fillTokens("");  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_EQ(tokens.at(0), "");
}


TEST_F(bowlingTest, oneSimpleToken)
{
  string s = "a";
  game.fillTokens(s);  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_EQ(tokens.at(0), s);
}


TEST_F(bowlingTest, twoEmptyTokens)
{
  game.fillTokens("|");  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_EQ(tokens.at(0), "");
  ASSERT_EQ(tokens.at(1), "");
}

TEST_F(bowlingTest, threeTokens)
{
  game.fillTokens("a|grrr|X");  
  auto tokens = game.getTokens();
  ASSERT_EQ(tokens.at(0), "a");
  ASSERT_EQ(tokens.at(1), "grrr");
  ASSERT_EQ(tokens.at(2), "X");
}


TEST_F(bowlingTest, fourTokens)
{
  game.fillTokens("a||X|123456");  
  auto tokens = game.getTokens();
  ASSERT_EQ(tokens.at(0), "a");
  ASSERT_EQ(tokens.at(1), "");
  ASSERT_EQ(tokens.at(2), "X");
  ASSERT_EQ(tokens.at(3), "123456");
}

TEST_F(bowlingTest, allTokens)
{
  game.fillTokens("X|7/|9-|X|-8|8/|-6|X|X|X||81");  
  auto tokens = game.getTokens();
  ASSERT_EQ(tokens.at(0), "X");
  ASSERT_EQ(tokens.at(1), "7/");
  ASSERT_EQ(tokens.at(2), "9-");
  ASSERT_EQ(tokens.at(3), "X");
  ASSERT_EQ(tokens.at(9), "X");
  ASSERT_EQ(tokens.at(10), "81");
}

TEST_F(bowlingTest, validationToMuchSigns)
{
    game.fillTokens("XXX|7/|9-|X|-8|8/|-6|X|X|X||81");
    ASSERT_FALSE(game.validateTokens());
}

TEST_F(bowlingTest, validationNotCorrectSigns)
{
    game.fillTokens("a||X|123456");
    ASSERT_FALSE(game.validateTokens());
    game.clearTokens();

    game.fillTokens("Y|7/|9-|X|-8|8/|-6|X|X|X||81");
    ASSERT_FALSE(game.validateTokens());
    game.clearTokens();

    game.fillTokens("X|7/|9-|X|-8|8/|-6|X|X|X||81");
    ASSERT_TRUE(game.validateTokens());
}

TEST_F(bowlingTest, validationTooLessSigns)
{
    game.fillTokens("|||X||81");
    ASSERT_FALSE(game.validateTokens());
    game.clearTokens();

    game.fillTokens("X|7/|9-|X|||-8|8/|-6|X|X|X||81");
    ASSERT_FALSE(game.validateTokens());
    game.clearTokens();

    game.fillTokens("X|7/|9-|X|||||-8|8/|-6|X|X|X||81");
    ASSERT_FALSE(game.validateTokens());
}

