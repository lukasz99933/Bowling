#pragma once

#include <string>
#include <vector>
#include <iterator>
#include <stdexcept>

using Frame = std::string;
using Frames = std::vector<Frame>;
using Iterator = Frames::iterator;

namespace Symbol 
{
  const char miss   = '-'; 
  const char spare  = '/'; 
  const char strike = 'X'; 
  const char separator = '|'; 
  
  const std::string correctSymbols = std::string() + miss + spare + strike + separator + "123456789";
}

bool inside(const std::string & s, const char ch);

class Bowling  
{
public:
  Bowling(const std::string& s);
  auto getFrames() const { return frames; };
  bool validateFrames();  
  int countExtras(); 
  int countScore();

private:
  void frameize(const std::string& s);
  Frames frames;
  bool validateFrame(const Frame& frame);
  int scoreFor2Balls(const Iterator & it);
  int countSeparateScore(const Frame& frame);  
  int countStandardScore();
  int sumAPair(const Frame& frame);
  int countExtra(const Iterator & it);
  bool isSymbolCorrect(const char symbol);
  bool areSymbolsCorrect(const Frame& frame);

  bool hasSpare(const Frame& frame);
  bool hasStrike(const Frame& frame);

  void eliminateDoubleSeparator(Frames & frames);
  bool isFrameSizeCorrect(const Frame& frame);

  int translateChar(const char ch); 

};


