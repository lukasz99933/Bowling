#include "validator.hpp"
#include <numeric>
#include <algorithm>

using namespace std;


Validator::Validator(const Frames& frames) 
{
  if (!validateFrames(frames))
    throw std::invalid_argument("Invalid input!");
}

bool Validator::validateFrames(const Frames& frames)
{
  return all_of(frames.begin(), 
                prev(frames.end()),
                [=](const Frame & frame)  { 
                  return validateFrame(frame); 
                } );       
}

bool Validator::validateFrame(Frame frame)
{
  return isFrameSizeCorrect(frame) and
         areSymbolsCorrect(frame) and
         not (frame.size()>1 and sumAPair(frame)>10) and
         frame[0] != Symbol::spare and
         not (frame.size()==2 and sumAPair(frame)==10 and frame[1] != Symbol::spare);
}

bool Validator::isFrameSizeCorrect(const Frame& frame)
{
  return frame.size() <= 2 and frame.size() > 0 ;
}

bool Validator::areSymbolsCorrect(const Frame& frame)
{
  return all_of(frame.begin(), 
                frame.end(), 
                [=](const char symbol)  { 
                  return isSymbolCorrect(symbol); 
                });
}


int sumAPair(const Frame& frame)
{
  return  hasSpare(frame)  ?  10  :  translateChar(frame[0]) + translateChar(frame[1]);                
}

bool Validator::isSymbolCorrect(const char ch)
{
  return inside(Symbol::correctSymbols, ch);
}

bool inside(const string & s, const char ch)
{
  return s.find(ch) != std::string::npos;
}


bool hasSpare(const Frame& frame)
{
  return frame.length() == 2 and frame[1] == Symbol::spare;
}

bool hasStrike(const Frame& frame)
{
  return frame[0] == Symbol::strike;
}

int translateChar(const char ch)
{
  if (ch==Symbol::miss or ch==Symbol::spare)
    return 0;
  else if (ch == Symbol::strike)
    return 10;
  return ch - '0';
}








