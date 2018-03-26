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

bool Bowling::goodSign(string token)
{
    for(char sign : token)
    {
        if(sign!='X' && sign!='/' && sign!='-' && sign!='|' && !isdigit(sign))
        {
            return false;
        }
    }
    return true;
}

bool Bowling::validateTokens()
{
    for(string token : tokens)
    {
        if(token.size()>2 || token.size()==0)
        {
            return false;
        }
	if(!goodSign(token))
	{
	    return false;
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

int Bowling::getPoints() const
{
  return points;
}

void Bowling::countBonuses()  
{
  for (int i=0; i<10; i++) {
    if ((tokens.at(i).length() == 2) and (tokens.at(i)[1] == '/'))
      bonuses.push_back(translateChar(tokens.at(i+1)[0]));
    else if (tokens.at(i)[0] == 'X') {
       if (tokens.at(i+1).length() == 2) {
         if (tokens.at(i+1)[1] == '/')
           bonuses.push_back(10);               
         else
           bonuses.push_back(translateChar(tokens.at(i+1)[0]) + translateChar(tokens.at(i+1)[1]));               
       }
       else if (tokens.at(i+1)[0] == 'X')
           bonuses.push_back(10 + translateChar(tokens.at(i+2)[0]));                             
    }  
    else
      bonuses.push_back(0);
  }
}

int Bowling::countSeparatePoints(std::string token)
{
	char firstChar = token[0];
    char secondChar = token[1];
	int points=0;
    if(isdigit(firstChar))
    {
	    if(secondChar=='/')
        {
    	    points += 10+(firstChar-'0');
        }
        else if(secondChar=='-')
        {
       		 points += (int)firstChar-'0';
        }
        else if(isdigit(secondChar))
        {
        	points += ((int)firstChar-'0') + ((int)secondChar-'0');
        }
	}
    else if(firstChar=='-')
    {
    	if(isdigit(secondChar))
        {
        	points += (int)secondChar-'0';
        }
    
	}

	return points;

}

void Bowling::countPoints()
{
    auto tokens = getTokens();
    int countStrikes=0;
    points=0;
    for(int i=0;i<10;i++)
    {
        auto token = tokens.at(i);

        if(token.compare("X")==0)
        {
            countStrikes++;
            points+=20;
        }
        else
        {
			points += countSeparatePoints(token);
        }
    }

    if(countStrikes==10)
    {
        points = 300;
    }
}
