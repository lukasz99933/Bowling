#include "bowling.hpp"
#include <string>

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

bool Bowling::validateIsCorrect(const vector<string>& tokens)
{
    for(string token : tokens)
    {
        if(token.size()>2)
        {
            return false;
        }

        for(char sign : token)
        {
            if(sign!='X' && sign!='/' && sign!='-' && sign!='|' && sign!='0' && sign!='1' && sign!='2' && sign!='3' && sign!='4' && sign!='5' && sign!='6' && sign!='7' && sign!='8' && sign!='9')
            {
                return false;
            }
        }
    }

   return true;
}


 
