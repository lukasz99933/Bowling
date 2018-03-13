#include "bowling.hpp"

using namespace std;

void Bowling::fillTokens(const string& s)
{
  if (s!="") 
    tokens.push_back(s);
}

vector<string> Bowling::getTokens()
{
  return tokens;
}


 
