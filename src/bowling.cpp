#include "bowling.hpp"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

Bowling::Bowling(const string& s)
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

vector<string> Bowling::getTokens() const
{
  return tokens;
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


vector<int> Bowling::getBonuses() const
{
  return bonuses;
}


void Bowling::countBonuses()  
{
  for (int i=0; i<10; i++) {
    if ((tokens.at(i).length() == 2) and (tokens.at(i)[1] == '/'))
      bonuses.push_back(translateChar(tokens.at(i+1)[0]));
    else
      bonuses.push_back(0);
  }
}
