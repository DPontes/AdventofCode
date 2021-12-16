#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <exception>
#include <fstream>
#include "helpers.h"

using matrix = std::vector<std::vector<int>>;


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

int getRating(matrix& matrix, const std::string& rule, const int& index)
{
  auto reading = getReading(matrix, rule, index);
  reading.insert(reading.begin(), matrix[0][0]);
  auto rating = binaryVector2Decimal(reading);

  return rating;
}

std::pair<int, int> getRatings(matrix& binaryMatrix)
{
  auto [firstMostCommonMatrix, firstLessCommonMatrix] = splitMostLessCommonMatrix(binaryMatrix);

  //int o2rating;
  //int co2rating;

  //std::thread t1([&o2rating](matrix& firstMostCommonMatrix, const std::string& rule, int index){
  //    o2rating = getRating(firstMostCommonMatrix, rule, index);
  //});

  //std::thread t2([&co2rating](matrix& firstLessCommonMatrix, const std::string& rule, int index){
  //    co2rating = getRating(firstLessCommonMatrix, rule, index);
  //});

  //t1.join();
  //t2.join();
  auto o2rating  = getRating(firstMostCommonMatrix, "most", 1);
  auto co2rating = getRating(firstLessCommonMatrix, "less", 1);

  return std::make_pair(o2rating, co2rating);
}


matrix readValuesIntoMatrix(std::ifstream& input)
{
  std::string binaryString;
  matrix binaryMatrix;

  while(getline(input, binaryString))
  {
    appendVectorToMatrix(binaryMatrix, binaryString);
  }

  return binaryMatrix;
}

int lifeSupportRating(std::ifstream& input)
{
  matrix binaryMatrix = readValuesIntoMatrix( input );
  auto [o2Rating, co2Rating] = getRatings(binaryMatrix);

  return o2Rating * co2Rating;
}


int main(int argc, char *argv[])
{
  try
  {
    std::ifstream input(argv[1], std::ios::in | std::ios::binary);
    if(!input) throw std::ios::failure("Error opening file!");

    auto result = lifeSupportRating( input );

    std::cout << "Life Support Rating: " << result << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
