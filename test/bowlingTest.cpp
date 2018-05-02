#include <gtest/gtest.h>
#include "bowling.hpp"

using namespace std;

class bowlingScoreParamTest : public ::testing::TestWithParam<pair<string,int>>
{
public:
  const string perfectScore = "X|X|X|X|X|X|X|X|X|X||XX";
  const string alwaysAlmostPerfect = "9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||";
  const string twentyOneFives = "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5";
  const string mixed = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
  const string perfectNoob = "--|--|--|--|--|--|--|--|--|--||";
};

class bowlingValidationParamTest : public ::testing::TestWithParam<string>
{
public:
};

TEST_P(bowlingScoreParamTest, countScore)
{
  Bowling game;
  ASSERT_EQ(game.countScore(GetParam().first),GetParam().second);
}

INSTANTIATE_TEST_CASE_P(countScores,
                        bowlingScoreParamTest,
                        ::testing::Values(make_pair("--|--|--|--|--|--|--|--|--|--||", 0),
                                          make_pair("X|X|X|X|X|X|X|X|X|X||XX",         10*30),
                                          make_pair("9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||", 10*9),
                                          make_pair("5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5",10*15),
                                          make_pair("X|7/|9-|X|-8|8/|-6|X|X|X||81",    167),
                                          make_pair("X|3/|--|--|--|--|--|--|--|--||",  10+10 + 10),
                                          make_pair("X|X|23|--|--|--|--|--|--|--||",   10+10+5 + 12+5),
                                          make_pair("X|34|--|--|--|--|--|--|--|--||",  10+7 + 7),
                                          make_pair("--|--|--|--|1-|--|--|--|--|--||", 1),
                                          make_pair("--|--|--|--|--|2-|--|--|--|--||", 2),
                                          make_pair("--|--|--|X|--|--|--|--|--|--||",  10),
                                          make_pair("--|--|--|--|--|--|8/|--|--|--||" ,10)
                                         ) ,   
                       );


TEST_P(bowlingValidationParamTest, incorrectData)
{
  Bowling game;
  ASSERT_THROW(game.countScore(GetParam()), std::invalid_argument);
}

INSTANTIATE_TEST_CASE_P(incorrectData,
                        bowlingValidationParamTest,
                        ::testing::Values("111|--|--|--|--|--|--|--|--|--||",
                                          "0-|--|--|--|--|--|--|--|--|--||",
                                          "/-|--|--|--|--|--|--|--|--|--||",
                                          "XXX|7/|9-|X|-8|8/|-6|X|X|X||81",
                                          "99|X|X|X|X|X|X|X|X|X||XX",
                                          "X|X|X|X|X|X||X|X|X|X|XX",
                                          "Y|7/|9-|X|-8|8/|-6|X|X|X||81",
                                          "|||X||81",
                                          "X|7/|9-|X|||-8|8/|-6|X|X|X||81",
                                          "--|--|--|19|--|--|--|--|--|--||"
                                         ) ,   
                       );

