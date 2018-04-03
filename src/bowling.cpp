#include "bowling.hpp"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void Bowling::frameize(const string& s)
{
  string s0 = s;
  string::size_type pos;
  while ((pos = s0.find("|")) != string::npos) {  
    frames.push_back(s0.substr(0,pos));
    s0 = s0.substr(pos+1, s0.length());  
  }
  frames.push_back(s0);
  if (frames.size() > 11) 
    frames.erase(frames.begin() + 10);
}


Bowling::Bowling(const string& s)
{
  frameize(s);
}


bool Bowling::goodSign(const string& frame)
{
    for(char sign : frame)
        if (sign!='X' and sign!='/' and sign!='-' and sign!='|' and not isdigit(sign))
            return false;
    return true;
}

bool isFrameSizeIncorrect(const string& frame)
{
  return frame.size() > 2 or frame.size() == 0 ;
}


bool Bowling::validateFrames()
{
    for(string frame : frames)
        if (isFrameSizeIncorrect(frame) or not goodSign(frame) or (frame.size()==2 and sumAPair(frame)>10))
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

bool isStrike(const string& frame)
{
  return frame[0] == 'X';
}

bool isSpare(const string& frame)
{
  return frame.length() == 2 and frame[1] == '/';
}


int Bowling::sumAPair(const string& frame)
{
   return  isSpare(frame)  ?  10  :  translateChar(frame[0]) + translateChar(frame[1]);                
}


int Bowling::scoreFor2Balls(const int i)
{
  return frames.at(i).length() == 2  ?  sumAPair(frames.at(i))  :  10 + translateChar(frames.at(i+1)[0]); 
}

int Bowling::countExtra(const int i)  
{
  if (isSpare(frames.at(i)))
    return translateChar(frames.at(i+1)[0]);
  else if (isStrike(frames.at(i))) 
    return scoreFor2Balls(i+1);
  return 0; 
}

int Bowling::countExtras()  
{
  int extraScore = 0;
  for(int i = first; i <= last; i++) 
    extraScore += countExtra(i);
  return extraScore;
}  
//

int Bowling::countSeparateScore(const string& frame)
{
  return  frame.length() == 1  ?   10  :  sumAPair(frame);
}

int Bowling::countStandardScore()
{  
  int score = 0;  
  for(int i = first; i <= last; i++) 
    score += countSeparateScore(frames[i]);
  return score;
}

int Bowling::countScore()
{
  validateFrames();
  return countStandardScore() + countExtras();
}
