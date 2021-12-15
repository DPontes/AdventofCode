#ifndef HELPERS_H
#define HELPERS_H

#include <math.h>

int convertCharToInt(const char& c)
{
  return (int) c - 48;
}


float getPower(const int& base, const float& exponent)
{
  return base * pow(2, exponent);
}


int binaryVector2Decimal(const std::vector<int>& vector)
{
  float decimal;

  for(auto it = 0; it != vector.size(); it++)
  {
    int power = vector.size() - it - 1;
    decimal += getPower(vector[it], power);
  }

  return (int) decimal;
}

#endif
