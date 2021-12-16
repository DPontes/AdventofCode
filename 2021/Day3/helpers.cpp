#include "helpers.h"

using matrix = std::vector<std::vector<int>>;


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

std::vector<int> appendString2Vector(const std::string& binaryString)
{
  std::vector<int> vBinary;

  auto it = binaryString.begin();

  for(it = binaryString.begin(); it != binaryString.end(); it++)
  {
    auto vectorIndex = std::distance(binaryString.begin(), it);
    vBinary.emplace_back(convertCharToInt(binaryString[vectorIndex]));
  }

  return vBinary;
}


void appendVectorToMatrix(matrix& binaryMatrix, const std::string& binaryString)
{
  binaryMatrix.emplace_back(appendString2Vector(binaryString));
}
