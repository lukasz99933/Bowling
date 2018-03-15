#include <gtest/gtest.h>
#include "bowling.hpp"

using namespace std;

class bowlingTest : public ::testing::Test
{
public:
  Bowling game;

// examples from readme.txt :
 const string exXs = "X|X|X|X|X|X|X|X|X|X||XX";
 const string ex9ms = "9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||";
 const string ex5s = "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5";
 const string exMixed = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
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

TEST_F(bowlingTest, mixedTokens)
{
  game.fillTokens(exMixed);  
  auto tokens = game.getTokens();
  ASSERT_EQ(tokens.at(0), "X");
  ASSERT_EQ(tokens.at(1), "7/");
  ASSERT_EQ(tokens.at(2), "9-");
  ASSERT_EQ(tokens.at(3), "X");
  ASSERT_EQ(tokens.at(4), "-8");
  ASSERT_EQ(tokens.at(5), "8/");
  ASSERT_EQ(tokens.at(6), "-6");
  ASSERT_EQ(tokens.at(7), "X");
  ASSERT_EQ(tokens.at(8), "X");
  ASSERT_EQ(tokens.at(9), "X");
  ASSERT_EQ(tokens.at(10), "81");
}

TEST_F(bowlingTest, xsTokens)
{
  game.fillTokens(exXs);  
  auto tokens = game.getTokens();
  ASSERT_EQ(tokens.at(0), "X");
  ASSERT_EQ(tokens.at(1), "X");
  ASSERT_EQ(tokens.at(2), "X");
  ASSERT_EQ(tokens.at(3), "X");
  ASSERT_EQ(tokens.at(4), "X");
  ASSERT_EQ(tokens.at(5), "X");
  ASSERT_EQ(tokens.at(6), "X");
  ASSERT_EQ(tokens.at(7), "X");
  ASSERT_EQ(tokens.at(8), "X");
  ASSERT_EQ(tokens.at(9), "X");
  ASSERT_EQ(tokens.at(10), "XX");
}

TEST_F(bowlingTest, _9minusTokens)
{
  game.fillTokens(ex9ms);  
  auto tokens = game.getTokens();
  ASSERT_EQ(tokens.at(0), "9-");
  ASSERT_EQ(tokens.at(1), "9-");
  ASSERT_EQ(tokens.at(2), "9-");
  ASSERT_EQ(tokens.at(3), "9-");
  ASSERT_EQ(tokens.at(4), "9-");
  ASSERT_EQ(tokens.at(5), "9-");
  ASSERT_EQ(tokens.at(6), "9-");
  ASSERT_EQ(tokens.at(7), "9-");
  ASSERT_EQ(tokens.at(8), "9-");
  ASSERT_EQ(tokens.at(9), "9-");
  ASSERT_EQ(tokens.at(10), "");
}

TEST_F(bowlingTest, _5slashTokens)
{
  game.fillTokens(ex5s);  
  auto tokens = game.getTokens();
  ASSERT_EQ(tokens.at(0), "5/");
  ASSERT_EQ(tokens.at(1), "5/");
  ASSERT_EQ(tokens.at(2), "5/");
  ASSERT_EQ(tokens.at(3), "5/");
  ASSERT_EQ(tokens.at(4), "5/");
  ASSERT_EQ(tokens.at(5), "5/");
  ASSERT_EQ(tokens.at(6), "5/");
  ASSERT_EQ(tokens.at(7), "5/");
  ASSERT_EQ(tokens.at(8), "5/");
  ASSERT_EQ(tokens.at(9), "5/");
  ASSERT_EQ(tokens.at(10), "5");
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


TEST_F(bowlingTest, translate1)
{
    ASSERT_EQ(translateChar('1'),1);
}


TEST_F(bowlingTest, translate2)
{
    ASSERT_EQ(translateChar('2'),2);
}

