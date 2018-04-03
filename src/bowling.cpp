#include "bowling.hpp"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void Bowling::frameize(const string& s)
{
  string s0 = s;
  string::size_type pos;
  while ((pos = s0.find(separator)) != string::npos) {  
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


bool Bowling::incorrectSign(const char sign)
{
  return (sign!=miss and sign!=spare and sign!=strike and sign!=separator and not isdigit(sign)) or sign=='0' ;
}

bool Bowling::correctSigns(const string& frame)
{
  for(char sign : frame)
     if (incorrectSign(sign))
        return false;
  return true;
}

bool isFrameSizeIncorrect(const string& frame)
{
  return frame.size() > 2 or frame.size() == 0 ;
}

auto butLast(const vector<string>& v)
{
  auto result(v);
  result.pop_back();
  return result;
}

bool Bowling::validateFrames()
{
    for(string frame : butLast(frames))
        if (isFrameSizeIncorrect(frame) or not correctSigns(frame) or (frame.size()==2 and sumAPair(frame)>10))
            return false;
    return (correctSigns(bonus())); 
}

int Bowling::translateChar(const char ch)
{
  if (ch==miss or ch==spare)
    return 0;
  else if (ch==strike)
    return 10;
  else
    return ch - '0';
}

bool Bowling::hasStrike(const string& frame)
{
  return frame[0] == strike;
}

bool Bowling::hasSpare(const string& frame)
{
  return frame.length() == 2 and frame[1] == spare;
}


int Bowling::scoreFor2Balls(const int i)
{
  return frames.at(i).length() == 2  ?  sumAPair(frames.at(i))  :  10 + translateChar(frames.at(i+1)[0]); 
}

int Bowling::countExtra(const int i)  
{
  if (hasSpare(frames.at(i)))
    return translateChar(frames.at(i+1)[0]);
  else if (hasStrike(frames.at(i))) 
    return scoreFor2Balls(i+1);
  return 0; 
}

int Bowling::countExtras()  
{  
  int extraScore = 0;
  for(vector<string>::size_type i = 0; i < frames.size() - 1; i++)
    extraScore += countExtra(i);
  return extraScore;
}  


int Bowling::sumAPair(const string& frame)
{
   return  hasSpare(frame)  ?  10  :  translateChar(frame[0]) + translateChar(frame[1]);                
}


int Bowling::countSeparateScore(const string& frame)
{
  return  frame.length() == 1  ?   10  :  sumAPair(frame);
}


int Bowling::countStandardScore()
{  
  int score = 0;  
  for(auto frame: butLast(frames)) 
    score += countSeparateScore(frame);
  return score;
}

int Bowling::countScore()
{
  if (validateFrames())
     return countStandardScore() + countExtras();
  else 
     return -1;
}
