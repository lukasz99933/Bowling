#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Bowling 
{
public:
  Bowling(const string& s);
  vector<string> getTokens();
  bool validateTokens();
private:
  vector<string> tokens;
};

int translateChar(const char ch);

