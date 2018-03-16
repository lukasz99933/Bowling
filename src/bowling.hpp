#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Bowling 
{
public:

  void fillTokens(const string& s);
  vector<string> getTokens();
  bool validateTokens();
  void clearTokens();
private:
  vector<string> tokens;
};

int translateChar(const char ch);

