#include <iostream>
#include <exception>
#include <fstream>

int isDeeper(int a, int b)
{
  return b > a;
}

int main(int argc, char *argv[])
{
  std::string sDepth;
  int previous = -1;
  int totalDepthIncrements = 0;

  try
  {
    std::ifstream input(argv[1], std::ios::in | std::ios::binary);
    if(!input) throw std::ios::failure("Error opening file!");

      int depth;
      while (getline(input, sDepth))
      {
        depth = std::stoi(sDepth);
        if(previous == -1)
        {
          previous = depth;
        }
        else
        {
          if(isDeeper(previous, depth)) totalDepthIncrements++;
          previous = depth;
        }
      }
      std::cout << "Total: " << totalDepthIncrements << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }


  return 0;
}
