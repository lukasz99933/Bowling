#pragma once

#include <string>
#include <vector>
#include <iostream>

using Frame = std::string;
using Frames = std::vector<Frame>;

Frames butLast(const Frames& v);

class Bowling  
{
public:
  Bowling(const Frame& s);
  auto getFrames() const { return frames; };  //public for tests only
  bool validateFrames();  
  int countExtras(); //public for tests only
  int countScore();
  int translateChar(const char ch); //public for tests only

private:
  const char miss   = '-';
  const char spare  = '/';
  const char strike = 'X';
  const char separator = '|';

  void frameize(const Frame& s);
  Frames frames;
  Frame bonusFrame() const;
  Frames standardFrames() const;
  bool validateFrame(const Frame& frame);
  int scoreFor2Balls(const int i);
  int countSeparateScore(const Frame& frame);  
  int countStandardScore();
  int sumAPair(const Frame& frame);
  int countExtra(const int i);
  bool correctSymbol(const char symbol);
  bool correctSymbols(const Frame& frame);

  bool hasSpare(const Frame& frame);
  bool hasStrike(const Frame& frame);

};


