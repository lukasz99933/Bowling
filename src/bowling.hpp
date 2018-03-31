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
  vector<string> tokens;
  int countSeparatePoints(std::string token);  
  int sumPair(const int i);
  int countExtra(const int i);
  bool goodSign(string token);
};

int translateChar(const char ch);

