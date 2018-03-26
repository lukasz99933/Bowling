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
  int countPoints();
private:
  vector<string> tokens;
  int countBonuses(vector<string> tokens);
  bool goodSign(string token);
  vector<int> bonuses;
  int countSeparatePoints(std::string token);  
};

int translateChar(const char ch);

