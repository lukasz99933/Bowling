#include <gtest/gtest.h>
#include "bowling.hpp"

using namespace std;

class bowlingTest : public ::testing::Test
{
public:
// examples:
 const string perfectScore = "X|X|X|X|X|X|X|X|X|X||XX";
 const string alwaysAlmostPerfect = "9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||";
 const string twentyOneFives = "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5";
 const string mixed = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
 const string perfectNoob = "--|--|--|--|--|--|--|--|--|--||";
};


// tests of fillTokens method:

TEST_F(bowlingTest, emptyToken)
{
  Bowling game("");  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_EQ(tokens.at(0), "");
}


TEST_F(bowlingTest, oneSimpleToken)
{
  string s = "a";
  Bowling game(s);  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_EQ(tokens.at(0), s);
}


TEST_F(bowlingTest, twoEmptyTokens)
{
  Bowling game("|");  
  auto tokens = game.getTokens();
  ASSERT_FALSE(tokens.empty());
  ASSERT_EQ(tokens.at(0), "");
  ASSERT_EQ(tokens.at(1), "");
}

TEST_F(bowlingTest, threeTokens)
{
  Bowling game("||");  
  auto tokens = game.getTokens();
  ASSERT_EQ(tokens.at(0), "");
  ASSERT_EQ(tokens.at(1), "");
  ASSERT_EQ(tokens.at(2), "");
}

TEST_F(bowlingTest, mixedTokens)
{
  Bowling game(mixed);  
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
  Bowling game(perfectScore);  
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
  Bowling game(alwaysAlmostPerfect);  
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
  Bowling game(twentyOneFives);  
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

// tests of validateTokens method:

TEST_F(bowlingTest, validationTooMuchSigns)
{
    Bowling game("XXX|7/|9-|X|-8|8/|-6|X|X|X||81");
    ASSERT_FALSE(game.validateTokens());
}

TEST_F(bowlingTest, validationTooMuchDigits)
{
    Bowling game("99|X|X|X|X|X|X|X|X|X||XX");
    ASSERT_FALSE(game.validateTokens());
}

TEST_F(bowlingTest, validationNotCorrectSigns)
{
    Bowling game1("a||X|123456");
    ASSERT_FALSE(game1.validateTokens());

    Bowling game2("Y|7/|9-|X|-8|8/|-6|X|X|X||81");
    ASSERT_FALSE(game2.validateTokens());

    Bowling game3(mixed);
    ASSERT_TRUE(game3.validateTokens());
}

TEST_F(bowlingTest, validationTooLessSigns)
{
    Bowling game1("|||X||81");
    ASSERT_FALSE(game1.validateTokens());

    Bowling game2("X|7/|9-|X|||-8|8/|-6|X|X|X||81");
    ASSERT_FALSE(game2.validateTokens());

    Bowling game3("X|7/|9-|X|||||-8|8/|-6|X|X|X||81");
    ASSERT_FALSE(game3.validateTokens());
}

// tests of translateChar function:

TEST_F(bowlingTest, translate1)
{
  ASSERT_EQ(translateChar('1'), 1);
  ASSERT_EQ(translateChar('2'), 2);
  ASSERT_EQ(translateChar('X'), 10);
  ASSERT_EQ(translateChar('-'), 0);
  ASSERT_EQ(translateChar('/'), 0);  // temporary
}


// test of extras:

TEST_F(bowlingTest, noExtras)
{
  Bowling game(perfectNoob);
  ASSERT_EQ(game.countExtras(), 0);
}

TEST_F(bowlingTest, extrasforFives)
{
  Bowling game(twentyOneFives);
  ASSERT_EQ(game.countExtras(), 50);
}

TEST_F(bowlingTest, doesExtraSum)
{
  Bowling game("X|34|--|--|--|--|--|--|--|--||");
  ASSERT_EQ(game.countExtras(), 7);
}


TEST_F(bowlingTest, doesExtraCountSpare)
{
  Bowling game("X|3/|--|--|--|--|--|--|--|--||");
  ASSERT_EQ(game.countExtras(), 10);
}

TEST_F(bowlingTest, twoStrikesExtra)
{

  Bowling game("X|X|23|--|--|--|--|--|--|--||");
  ASSERT_EQ(game.countExtras(), 17);
}

TEST_F(bowlingTest, perfectExtra)
{
  Bowling game(perfectScore);
  ASSERT_EQ(game.countExtras(), 200);
}

// test of total score:

TEST_F(bowlingTest, countScore)
{
    Bowling game1(perfectScore);
    ASSERT_EQ(game1.countScore(),300);

    Bowling game2(alwaysAlmostPerfect);
    ASSERT_EQ(game2.countScore(), 90);

    Bowling game3(twentyOneFives);
    ASSERT_EQ(game3.countScore(),150);

    Bowling game4(mixed);
    ASSERT_EQ(game4.countScore(),167);

    Bowling game5("X|3/|--|--|--|--|--|--|--|--||");
    ASSERT_EQ(game5.countScore(),10+10 + 10);

    Bowling game6("X|X|23|--|--|--|--|--|--|--||");
    ASSERT_EQ(game6.countScore(),10+10+5 + 12 + 5);

    Bowling game7("X|34|--|--|--|--|--|--|--|--||");
    ASSERT_EQ(game7.countScore(),10+7 + 7);
}


