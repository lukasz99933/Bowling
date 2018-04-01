#pragma once

#include <string>
#include <vector>

using namespace std;


class Bowling 
{
public:
  Bowling(const string& s);
  vector<string> getTokens() const { return tokens; };
  bool validateTokens();
  int countExtras(); //public for tests
  int countScore();

private:
  const int first = 0, last = 9;
  vector<string> tokens;
  int countSeparatePoints(const string& token);  
  int countStandardPoints();
  int sumAPair(const string& token);
  int countExtra(const int i);
  bool goodSign(const string& token);
};

int translateChar(const char ch);

