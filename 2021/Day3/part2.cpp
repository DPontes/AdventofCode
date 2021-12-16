#include "ratings.h"
#include <fstream>
#include <iostream>
#include <exception>

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
