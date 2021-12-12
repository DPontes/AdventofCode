#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <exception>
#include <fstream>

int convertCharToInt(const char& c)
{
  return (int) c - 48;
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


void appendVectorToMatrix(std::vector<std::vector<int>>& binaryMatrix, const std::string& binaryString)
{
  binaryMatrix.emplace_back(appendString2Vector(binaryString));
}


int lifeSupportRating(std::ifstream& input)
{
  std::string binaryString;
  size_t nReads = 0;
  std::vector<std::vector<int>> binaryMatrix;

  while(getline(input, binaryString))
  {
    nReads++;
    appendVectorToMatrix(binaryMatrix, binaryString);
  }

  // Continue here, now that the matrix is filled up

  return 0;
}


int main(int argc, char *argv[])
{
  try
  {
    std::ifstream input(argv[1], std::ios::in | std::ios::binary);
    if(!input) throw std::ios::failure("Error opening file!");

    std::cout << "Life Support Rating: " << lifeSupportRating( input ) << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
