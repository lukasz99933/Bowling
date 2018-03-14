#include "bowling.hpp"

using namespace std;

void Bowling::fillTokens(const string& s)
{
  auto pos = s.find("|");
 
  string s1 = s.substr(0,pos);
  tokens.push_back(s1);
  s1 = s.substr(pos+1, s.length());
  tokens.push_back(s1);
}

vector<string> Bowling::getTokens()
{
  return tokens;
}


 
