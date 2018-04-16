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

bool hasSpare(const Frame& frame);
bool hasStrike(const Frame& frame);


class Framization
{
public:
  Framization(const std::string& s);
  Frames getFrames() const& {return frames;};
private:
  Frames frames;

  void eliminateDoubleSeparator(Frames & frames);
};

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


