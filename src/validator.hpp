#pragma once

#include "framization.hpp"
#include <string>


int sumAPair(const Frame& frame);
bool inside(const std::string & s, const char ch);
bool hasSpare(const Frame& frame);
bool hasStrike(const Frame& frame);
int translateChar(const char ch);


class Validator  
{
public: 
  Validator(const Frames& frames);  

private:
  bool validateFrames(const Frames& frames);  
  bool validateFrame(Frame frame);
  bool isFrameSizeCorrect(const Frame& frame);
  bool areSymbolsCorrect(const Frame& frame);
  bool isSymbolCorrect(const char symbol);
  int translateChar(const char ch); 
};


