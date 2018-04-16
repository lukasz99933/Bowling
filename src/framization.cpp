#include "framization.hpp"
#include <cctype>
#include <numeric>
#include <algorithm>

using namespace std;

void Framization::eliminateDoubleSeparator(Frames & frames)
{
  if (frames.size() > 11) 
    frames.erase(frames.begin() + 10);
}


Framization::Framization(const string& s)
{
  Frame s0 = s;
  Frame::size_type pos;
  while ((pos = s0.find(Symbol::separator)) != Frame::npos) 
  {  
    frames.push_back(s0.substr(0, pos));
    s0 = s0.substr(pos+1, s0.length());  
  }
  frames.push_back(s0);
  eliminateDoubleSeparator(frames);

}


