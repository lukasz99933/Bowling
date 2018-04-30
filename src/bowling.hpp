#pragma once
#include "framization.hpp"

#include <string>

bool inside(const std::string & s, const char ch);

class Bowling  
{
public:
  int countScore(const std::string& input);

private:
  int scoreFor2Balls(const Iterator & it);
  int countSeparateScore(const Frame& frame);  
  int countStandardScore(const Frames& frames);
  int countExtra(const Iterator & it);
  int countExtras(Frames frames);
};


