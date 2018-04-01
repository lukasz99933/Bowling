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


bool Bowling::goodSign(const string& token)
{
    for(char sign : token)
        if(sign!='X' and sign!='/' and sign!='-' and sign!='|' and !isdigit(sign))
            return false;
    return true;
}

bool Bowling::validateTokens()
{
    for(string token : tokens)
        if(token.size()>2 or token.size()==0 or !goodSign(token))
            return false;
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

int Bowling::sumPair(const string& token)
{
   return  token[1] == '/'  ?  10  :  translateChar(token[0]) + translateChar(token[1]);                
}

int Bowling::countExtra(const int i)  
{
  if ((tokens.at(i).length() == 2) and (tokens.at(i)[1] == '/'))
      return translateChar(tokens.at(i+1)[0]);
  else if (tokens.at(i)[0] == 'X') {
      if (tokens.at(i+1).length() == 2) 
          return sumPair(tokens.at(i+1));
      else if (tokens.at(i+1)[0] == 'X')
          return 10 + translateChar(tokens.at(i+2)[0]);                 
  }  
  return 0;
}

int Bowling::countExtras()  
{
  int result = 0;
  for (int i=0; i<10; i++) 
    result += countExtra(i);
  return result;
}


int Bowling::countSeparatePoints(const std::string token)
{
  return  token.length() == 1  ?   translateChar(token[0])  :  sumPair(token);
}

int Bowling::countScore()
{
  validateTokens();
  int points = countExtras();
  for(int i=0; i<10; i++) 
    points += countSeparatePoints(tokens[i]);
  return points;
}
