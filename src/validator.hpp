#pragma once

#include "framization.hpp"
#include <string>

bool inside(const std::string & s, const char ch);
int sumAPair(const Frame& frame);
bool hasStrike(const Frame& frame);
bool hasSpare(const Frame& frame);
int translateChar(const char ch);

class Validator  
{
public: 
  Validator(const Frames& frames);  
private:
  bool isFrameSizeCorrect(const Frame& frame);
  int translateChar(const char ch); 
  bool isSymbolCorrect(const char symbol);
  bool areSymbolsCorrect(const Frame& frame);
  bool validateFrame(Frame frame);
  bool validateFrames(const Frames& frames);  
};


