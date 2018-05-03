#pragma once


class Accumulator 
{
public:
  Accumulator() : value_(0) {};

  Accumulator operator++ ();
  Accumulator operator+= ( int & i);
  Accumulator operator=  ( int & i);
  int operator=  (Accumulator & accu);
  Accumulator operator+  (int & i);
  Accumulator operator+  ( Accumulator & accu);
  bool operator== (const int & i);

private:
  int value_;
};


