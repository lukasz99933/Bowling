#include "framization.hpp"
#include <cctype>
#include <numeric>

using namespace std;

void Framization::eliminateDoubleSeparator(Frames & frames)
{
  if (frames.size() > 11) 
    frames.erase(frames.begin() + 10);
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


