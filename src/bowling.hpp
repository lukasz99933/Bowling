#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Bowling 
{
public:
  void fillTokens(const string& s);
  vector<string> getTokens();
  bool validateIsCorrect(const vector<string>& tokens);
private:
  vector<string> tokens;
};

