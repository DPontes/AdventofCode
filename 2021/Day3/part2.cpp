#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <exception>
#include <fstream>

using matrix = std::vector<std::vector<int>>;


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


void appendVectorToMatrix(matrix& binaryMatrix, const std::string& binaryString)
{
  binaryMatrix.emplace_back(appendString2Vector(binaryString));
}


std::vector<int> getCommonVector( const matrix& internalMatrix, const std::string rule)
{
  std::vector<int> commonVector;
  commonVector.resize(internalMatrix[0].size());

  // mostCommonVector populated by the sum of each column
  // TODO: surely there's a better way...?
  for(auto it1 = 0; it1 != internalMatrix.size(); it1++)
  {
    for(auto it2 = 0; it2 != internalMatrix[it1].size(); it2++)
    {
      commonVector[it2] += internalMatrix[it1][it2];
    }
  }

  // Transform a vector of sums into a vector of the most common element [0, 1]
  for(auto it = 0; it != commonVector.size(); it++)
  {
    float matrixSize = internalMatrix.size();
    if(rule == "most")
    {
        commonVector[it] = (commonVector[it] >= matrixSize / 2.0) ? 1 : 0;
    }
    else
    {
        commonVector[it] = (commonVector[it] < matrixSize / 2.0) ? 1 : 0;
    }
  }

  return commonVector;
}


std::pair<matrix, matrix> splitMostLessCommonMatrix(matrix& binaryMatrix)
{

  auto mostCommonVector = getCommonVector(binaryMatrix, "most");

  matrix firstMostCommonMatrix;
  matrix firstLessCommonMatrix;

  for(auto it = 0; it != binaryMatrix.size(); it++)
  {
    if(binaryMatrix[it][0] == mostCommonVector[0]) firstMostCommonMatrix.emplace_back(binaryMatrix[it]);
    else firstLessCommonMatrix.emplace_back(binaryMatrix[it]);
  }

  return std::make_pair(firstMostCommonMatrix, firstLessCommonMatrix);
}

// Recursive function
std::vector<int> getReading(const matrix internalMatrix, const std::string rule, int index)
{
  matrix newMatrix;
  auto commonVector = getCommonVector(internalMatrix, rule);
  std::vector<int> rating;

  // if there is only one row left, stop and return the rest of the vector
  if(internalMatrix.size() == 1)
  {
      std::vector<int> newVectorFromMatrix;
      for(int i = index; i < internalMatrix[0].size(); i++)
      {
        newVectorFromMatrix.emplace_back(internalMatrix[0][i]);
      }
      return newVectorFromMatrix;
  }
  else
  {
      for(auto it = 0; it != internalMatrix.size(); it++)
      {
        if(internalMatrix[it][index] == commonVector[index])    newMatrix.emplace_back(internalMatrix[it]);
      }
      rating.emplace_back(commonVector[index]);
  }

  index++;
  if(index < newMatrix[0].size())
  {
    std::vector<int> prev_rating = getReading(newMatrix, rule, index);
    rating.insert(rating.end(), prev_rating.begin(), prev_rating.end());
  }

  return rating;
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


std::pair<int, int> getRatings(matrix& binaryMatrix)
{
  auto [firstMostCommonMatrix, firstLessCommonMatrix] = splitMostLessCommonMatrix(binaryMatrix);

  // this can be refactored into two calls of a function
  auto o2reading  = getReading(firstMostCommonMatrix, "most", 1);
  o2reading.insert(o2reading.begin(), firstMostCommonMatrix[0][0]);
  auto o2rating = binaryVector2Decimal(o2reading);

  auto co2reading = getReading(firstLessCommonMatrix, "less", 1);
  co2reading.insert(co2reading.begin(), firstLessCommonMatrix[0][0]);
  auto co2rating = binaryVector2Decimal(co2reading);

  return std::make_pair(o2rating, co2rating);
}


int lifeSupportRating(std::ifstream& input)
{
  std::string binaryString;
  matrix binaryMatrix;

  while(getline(input, binaryString))
  {
    appendVectorToMatrix(binaryMatrix, binaryString);
  }

  auto [o2Rating, co2Rating] = getRatings(binaryMatrix);

  return o2Rating * co2Rating;
}


int main(int argc, char *argv[])
{
  try
  {
    std::ifstream input(argv[1], std::ios::in | std::ios::binary);
    if(!input) throw std::ios::failure("Error opening file!");

    auto result = lifeSupportRating( input);

    std::cout << "Life Support Rating: " << result << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
