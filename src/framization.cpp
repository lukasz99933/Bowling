#include "framization.hpp"
#include <cctype>
#include <numeric>

using namespace std;

void Framization::eliminateDoubleSeparator(Frames & frames)
{
  const int FRAMES_NO = 10;
  if (frames.size() > FRAMES_NO + 1) {
    if (*((frames.begin() + FRAMES_NO)) == "")
      frames.erase(frames.begin() + FRAMES_NO);
    else
      *((frames.begin() + FRAMES_NO)) = "ERROR";
  }
}


Framization::Framization(const string& input)
{
  Frame rest = input;
  Frame::size_type pos;
  while ((pos = rest.find(Symbol::separator)) != Frame::npos) 
  {  
    frames.push_back(rest.substr(0, pos));
    rest = rest.substr(pos+1, rest.length());  
  }
  frames.push_back(rest);
  eliminateDoubleSeparator(frames);

}


