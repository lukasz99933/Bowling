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
  vector<int> getBonuses() const;
  int getPoints() const;
  void countBonuses();
  void countPoints();
  bool goodSign(string token);
private:
  vector<string> tokens;
  vector<int> bonuses;
  int points;
};

int translateChar(const char ch);

