#pragma once

#include <string>
#include <vector>
#include <iterator>

using Frame = std::string;
using Frames = std::vector<Frame>;
using Iterator = Frames::iterator;

namespace Symbol 
{
  const char miss   = '-'; 
  const char spare  = '/'; 
  const char strike = 'X'; 
  const char separator = '|'; 
  
  const std::string correctSymbols = std::string() + miss + spare + strike + separator + "123456789";
}


class Framization
{
public:
  Framization(const std::string& input);
  Frames getFrames() const& {return frames;};
private:
  Frames frames;

  void eliminateDoubleSeparator(Frames& frames);
};



