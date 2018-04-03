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

private:
  void frameize(const string& s);
  vector<string> frames;
  bool validateFrame(const string& frame);
  int scoreFor2Balls(const int i);
  int countSeparateScore(const string& frame);  
  int countStandardScore();
  int sumAPair(const string& frame);
  int countExtra(const int i);
  bool goodSign(const string& frame);
};

int translateChar(const char ch);

