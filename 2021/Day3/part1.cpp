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


void addBinaryStringToVector(std::vector<int>& binaryVector, const std::string& binaryString)
{
  auto it = binaryString.begin();

  for(it = binaryString.begin(); it != binaryString.end(); it++)
  {
    auto vectorIndex = std::distance(binaryString.begin(), it);
    binaryVector[vectorIndex] += convertCharToInt(binaryString[vectorIndex]);
  }
}


void resizeVector(std::vector<int>& binaryVector, const std::string& binaryString)
{
  binaryVector.resize(binaryString.size());
}

float getPower(const int& base, const float& exponent)
{
  return base * pow(2, exponent);
}

int getGammaEpsilonProduct(std::vector<int>& binaryVector, const size_t& nReads)
{
  float vectorSize = binaryVector.size();
  auto gammaRate = 0;
  auto epsilonRate = 0;

  auto it = binaryVector.begin();

  for(it = binaryVector.begin(); it != binaryVector.end(); it++)
  {
    auto vectorIndex = std::distance(binaryVector.begin(), it);
    auto power = vectorSize - vectorIndex - 1;

    int gammaBinary = (binaryVector[vectorIndex] > nReads / 2) ? 1 : 0;
    gammaRate += getPower(gammaBinary, power);

    int epsilonBinary = (binaryVector[vectorIndex] > nReads / 2) ? 0 : 1;
    epsilonRate += getPower(epsilonBinary, power);
  }

  return gammaRate * epsilonRate;
}


int getPowerConsumption(std::ifstream& input)
{
  std::string binaryString;
  size_t nReads = 0;
  size_t powerConsumption;
  bool first = true;
  std::vector<int> binaryVector;

  while(getline(input, binaryString))
  {
    nReads++;
    if (first) {
      first = false;
      resizeVector(binaryVector, binaryString);
    }

  addBinaryStringToVector(binaryVector, binaryString);
  }

  powerConsumption = getGammaEpsilonProduct(binaryVector, nReads);

  return powerConsumption;
}


int main(int argc, char *argv[])
{
  try
  {
    std::ifstream input(argv[1], std::ios::in | std::ios::binary);
    if(!input) throw std::ios::failure("Error opening file!");

    std::cout << "Power Consumption: " << getPowerConsumption( input ) << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
