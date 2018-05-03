#include "Accumulator.hpp"

Accumulator Accumulator::operator++ () { 
  value_++; 
  return *this;
}

Accumulator Accumulator::operator+= (int & i) { 
  value_ += i; 
  return *this;
}

Accumulator Accumulator::operator= (int & i) { 
  value_ = i; 
  return *this;
}

int Accumulator::operator=  (Accumulator & accu) {
  return accu.value_;
}

Accumulator Accumulator::operator+  ( int & i) {
  value_ = this->value_ + i; 
  return *this;
}

Accumulator Accumulator::operator+  ( Accumulator & accu) {
  value_ = this->value_ + accu.value_; 
  return *this;
}

bool Accumulator::operator== (const int & i) {
  return value_ == i; 
}


