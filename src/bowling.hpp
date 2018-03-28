#pragma once

#include <string>
#include <vector>

using namespace std;


class Bowling 
{
public:
  Bowling(const string& s);
  vector<string> getTokens() const;
  bool validateTokens();
  vector<int> getExtras() const;
//  int getPoints() const;
  void countExtras();
  int countScore();
  bool goodSign(string token);
private:
  vector<string> tokens;
  vector<int> extras;
  int countSeparatePoints(std::string token);  
};

int translateChar(const char ch);

