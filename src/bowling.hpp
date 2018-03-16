#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Bowling 
{
public:
  Bowling(const string& s);
  vector<string> getTokens() const;
  bool validateTokens();
  vector<int> getBonuses() const;
  void countBonuses();
private:
  vector<string> tokens;
  vector<int> bonuses;
};

int translateChar(const char ch);

