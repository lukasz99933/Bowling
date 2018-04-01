#pragma once

#include <string>
#include <vector>

using namespace std;


class Bowling 
{
public:
  Bowling(const string& s);
  vector<string> getTokens() const { return tokens; };  //public for tests only
  bool validateTokens();  
  int countExtras(); //public for tests only
  int countScore();

private:
  const int first = 0, last = 9;
  void tokenize(const string& s);
  vector<string> tokens;
  int scoreFor2Balls(const int i);
  int countSeparatePoints(const string& token);  
  int countStandardPoints();
  int sumAPair(const string& token);
  int countExtra(const int i);
  bool goodSign(const string& token);
};

int translateChar(const char ch);

