#pragma once

#include <string>
#include <vector>

using namespace std;


class Bowling  
{
public:
  Bowling(const string& s);
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

  void frameize(const string& s);
  vector<string> frames;
  bool validateFrame(const string& frame);
  int scoreFor2Balls(const int i);
  int countSeparateScore(const string& frame);  
  int countStandardScore();
  int sumAPair(const string& frame);
  int countExtra(const int i);
  bool correctSign(const char sign);
  bool correctSigns(const string& frame);

  bool hasSpare(const string& frame);
  bool hasStrike(const string& frame);

};


