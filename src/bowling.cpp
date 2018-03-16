#include "bowling.hpp"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void Bowling::fillTokens(const string& s)
{
  string s0 = s;
  string::size_type pos;
  while ((pos = s0.find("|")) != string::npos) {  
    tokens.push_back(s0.substr(0,pos));
    s0 = s0.substr(pos+1, s0.length());  
  }
  tokens.push_back(s0);
  if (tokens.size() > 11) 
    tokens.erase(tokens.begin() + 10);
}

vector<string> Bowling::getTokens()
{
  return tokens;
}

void Bowling::clearTokens()
{
    tokens.clear();
}

bool Bowling::validateTokens()
{
    for(string token : tokens)
    {
        if(token.size()>2 || token.size()==0)
        {
            return false;
        }

        for(char sign : token)
        {
            if(sign!='X' && sign!='/' && sign!='-' && sign!='|' && !isdigit(sign))
            {
                return false;
            }
        }
    }

   return true;
}


int translateChar(const char ch)
{
  switch(ch) {
    case 'X': return 10;
    case '-': return 0;
    case '/': return 0;
    default : return ch - '0';
  }
}

 
