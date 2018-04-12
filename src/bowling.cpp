#include "bowling.hpp"
#include <iostream>
#include <cctype>
#include <numeric>
#include <algorithm>

using namespace std;

void Bowling::frameize(const string& s)
{
  Frame s0 = s;
  Frame::size_type pos;
  while ((pos = s0.find(Symbol::separator)) != Frame::npos) {  
    frames.push_back(s0.substr(0,pos));
    s0 = s0.substr(pos+1, s0.length());  
  }
  frames.push_back(s0);
  if (frames.size() > 11) 
    frames.erase(frames.begin() + 10);
}

Frame Bowling::bonusFrame() const 
{
  return frames.back();
}


Frames Bowling::standardFrames() const 
{
  return butLast(frames);
}


Bowling::Bowling(const string& s)
{
  frameize(s);
  validateFrames();
}


bool Bowling::correctSymbol(const char symbol)
{
  return symbol==Symbol::miss or symbol==Symbol::spare or symbol==Symbol::strike or symbol==Symbol::separator or (isdigit(symbol) and symbol!='0') ;
}

bool Bowling::correctSymbols(const Frame& frame)
{
  for(char symbol : frame)
     if (not correctSymbol(symbol))
        return false;
  return true;
}

bool isFrameSizeIncorrect(const Frame& frame)
{
  return frame.size() > 2 or frame.size() == 0 ;
}

Frames butLast(const Frames& fr)
{
  auto result(fr);
  result.pop_back();
  return result;
}

bool Bowling::validateFrames()
{
    for(Frame frame : standardFrames())
        if (isFrameSizeIncorrect(frame) or not correctSymbols(frame) or (frame.size()==2 and sumAPair(frame)>10))
            return false;
    return (correctSymbols(bonusFrame())); 
}

int Bowling::translateChar(const char ch)
{
  if (ch==Symbol::miss or ch==Symbol::spare)
    return 0;
  else if (ch==Symbol::strike)
    return 10;
  else
    return ch - '0';
}

bool Bowling::hasStrike(const Frame& frame)
{
  return frame[0] == Symbol::strike;
}

bool Bowling::hasSpare(const Frame& frame)
{
  return frame.length() == 2 and frame[1] == Symbol::spare;
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
  int i=0;
  return accumulate(frames.begin(), prev(frames.end()), 0, 
              [&](int sum, Frame frame) 
              { 
                return sum + countExtra(i++);
                if (frame.length()>0) 
                  i++;  
              });
} 


int Bowling::sumAPair(const Frame& frame)
{
   return  hasSpare(frame)  ?  10  :  translateChar(frame[0]) + translateChar(frame[1]);                
}


int Bowling::countSeparateScore(const Frame& frame)
{
  return  frame.length() == 1  ?   10  :  sumAPair(frame);
}


int Bowling::countStandardScore()
{  
  return accumulate(frames.begin(), prev(frames.end()), 0, 
              [=](int sum, Frame frame) 
              { 
                return sum + countSeparateScore(frame);
              });
}

int Bowling::countScore()
{
  if (validateFrames())
     return countStandardScore() + countExtras();
  else 
     return -1;
}
