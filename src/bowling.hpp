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
  int countExtra(const int i);
  int countExtras();
  int countScore();
  bool goodSign(string token);
private:
  vector<string> tokens;
  int countSeparatePoints(std::string token);  
};

int translateChar(const char ch);

