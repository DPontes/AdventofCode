#include "helpers.h"
#include "ratings.h"

using matrix = std::vector<std::vector<int>>;


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


/* Recursive function
   Will run until index = newMatrix[0].size()
*/
std::vector<int> getReading(const matrix& internalMatrix, const std::string& rule, int index)
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
  auto rating = binaryVector2Decimal(reading);

  return rating;
}


std::pair<int, int> getRatings(matrix& binaryMatrix)
{
  auto o2rating  = getRating(binaryMatrix, "most", 0);
  auto co2rating = getRating(binaryMatrix, "less", 0);

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

