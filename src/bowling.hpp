#pragma once

#include <string>
#include <vector>
#include <iterator>
#include <stdexcept>
#include "framization.hpp"


bool inside(const std::string & s, const char ch);

bool hasSpare(const Frame& frame);
bool hasStrike(const Frame& frame);

class Bowling  
{
public:
  int countScore(const std::string& input);

private:
  int scoreFor2Balls(const Iterator & it);
  int countSeparateScore(const Frame& frame);  
  int countStandardScore(const Frames& frames);
  int sumAPair(const Frame& frame);
  int countExtra(const Iterator & it);
  int countExtras(Frames frames);

  bool isFrameSizeCorrect(const Frame& frame);
  bool isSymbolCorrect(const char symbol);
  bool areSymbolsCorrect(const Frame& frame);

  bool validateFrames(const Frames& frames);  
  bool validateFrame(Frame frame);

  int translateChar(const char ch); 

};


