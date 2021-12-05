#include <iostream>
#include <exception>
#include <fstream>
#include <vector>

const int isDeeper(int* a, int* b)
{
  return *b > *a;
}

const int countTotalDepthIncrements(std::ifstream& input)
{
  std::string sDepth;
  std::vector<int> depths;
  int depth;
  int sumPrev = -1;
  int sumDepth;
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
    if (depths.size() < 4) continue;
    sumPrev = (depths.back() - 1) + (depths.back() - 2) + (depths.back() -3 );
    sumDepth = (depths.back()) + (depths.back() - 1) + (depths.back() - 2);

    if(isDeeper(&sumPrev, &sumDepth)) totalDepthIncrements++;
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
