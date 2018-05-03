#pragma once
#include "framization.hpp"

#include <string>

bool inside(const std::string & s, const char ch);

class Bowling  
{
public:
  int countScore(const std::string& input);

private:
  int countStandardScore(const Frames& frames);
  int countExtras(Frames frames);
  int countSeparateScore(const Frame& frame);  
  int countExtra(const Iterator & it);
  int scoreFor2Balls(const Iterator & it);
};


