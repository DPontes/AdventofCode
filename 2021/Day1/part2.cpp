#include <iostream>
#include <exception>
#include <fstream>
#include <vector>

const int isHigher(const int* previous, const int* current)
{
  return *previous < *current;
}

/*
    Given n, where n is the last element of vector "depths",
    it returns a pair containing:
    - sumPrevious: depths[n-1] + depths[n-2] + depths[n-3]
    - sumCurrent:  depths[n]   + depths[n-1] + depths[n-2]
*/
std::pair<int, int> sumsPrevAndDepth(std::vector<int> d)
{
  int sumPrevious = ( d.end()[-2] ) + ( d.end()[-3] ) + ( d.end()[-4] );
  int sumCurrent  = ( d.end()[-1] ) + ( d.end()[-2] ) + ( d.end()[-3] );

  return std::make_pair(sumPrevious, sumCurrent);
}

const int countTotalDepthIncrements(std::ifstream& input)
{
  std::string sDepth;
  std::vector<int> depths;
  int depth;
  int totalDepthIncrements = 0;

  while (getline(input, sDepth))
  {
    try
    {
        depth = std::stoi(sDepth);
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "Input value is not a number.. Exiting" << std::endl;
        throw;
    }

    depths.emplace_back(depth);

    // As the implementation only works when the vector "depths" has 4+ elements,
    // we skip the rest of the implementation until then
    if (depths.size() > 3)
    {
      const auto [sumPrevious, sumCurrent] = sumsPrevAndDepth(depths);
      if(isHigher(&sumPrevious, &sumCurrent)) totalDepthIncrements++;
    }
  }
  return totalDepthIncrements;
}

int main(int argc, char *argv[])
{

  try
  {
    std::ifstream input(argv[1], std::ios::in | std::ios::binary);
    if(!input) throw std::ios::failure("Error opening file!");

    std::cout << "Total: " << countTotalDepthIncrements( input ) << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
