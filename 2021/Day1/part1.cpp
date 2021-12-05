#include <iostream>
#include <exception>
#include <fstream>

const int isDeeper(int* a, int* b)
{
  return *b > *a;
}

const int countTotalDepthIncrements(std::ifstream& input)
{
  std::string sDepth;
  int depth;
  int previous = -1;
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

    if(previous == -1) previous = depth;
    else
    {
      if(isDeeper(&previous, &depth)) totalDepthIncrements++;
      previous = depth;
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
