#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Bowling 
{
public:
  void fillTokens(const string& s);
  vector<string> getTokens();
private:
  vector<string> tokens;
};

