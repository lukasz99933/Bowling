#pragma once

#include <string>
#include <vector>

using namespace std;


class Bowling  
{
public:
  Bowling(const string& s);
  vector<string> getFrames() const { return frames; };  //public for tests only
  bool validateFrames();  
  int countExtras(); //public for tests only
  int countScore();

private:
  const int first = 0, last = 9;
  void frameize(const string& s);
  vector<string> frames;
  int scoreFor2Balls(const int i);
  int countSeparatePoints(const string& frame);  
  int countStandardPoints();
  int sumAPair(const string& frame);
  int countExtra(const int i);
  bool goodSign(const string& frame);
};

int translateChar(const char ch);

