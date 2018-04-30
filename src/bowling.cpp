#include "bowling.hpp"
#include "validator.hpp"
#include <algorithm>

using namespace std;

int Bowling::scoreFor2Balls(const Iterator & it)
{
  return it->length() == 2  ?  sumAPair(*it)  :  10 + translateChar((*next(it))[0]); 
}

int Bowling::countExtra(const Iterator & it)  
{
  const Frame frame = *it;
  const Frame nextFrame = *next(it);

  if (hasSpare(frame))
    return translateChar(nextFrame[0]);
  else if (hasStrike(frame)) 
    return scoreFor2Balls(next(it));
  return 0; 
}


int Bowling::countExtras(Frames frames)  
{  
  Iterator it = frames.begin();
  return accumulate(it, 
                    prev(frames.end()), 
                    0, 
                    [&](int & sum, const Frame & frame) 
                    { 
                      return sum + countExtra(it++);
                      (void)(frame);
                    });
} 




int Bowling::countSeparateScore(const Frame& frame)
{
  return  frame.length() == 1  ?   10  :  sumAPair(frame);
}


int Bowling::countStandardScore(const Frames& frames)
{  
  return accumulate(frames.begin(), 
                    prev(frames.end()), 
                    0, 
                    [=](int & sum, const Frame & frame) 
                    { 
                      return sum + countSeparateScore(frame);
                    });
}


int Bowling::countScore(const string& input)
{
  Framization framization(input);
  Frames frames = framization.getFrames();
  Validator validator(frames);
  return countStandardScore(frames) + countExtras(frames);
}
