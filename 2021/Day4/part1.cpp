#include <fstream>
#include <iostream>
#include <exception>

auto getScore(std::ifstream& input)
{
    return 0;
}

int main(int argc, char *argv[])
{
  try
  {
    std::ifstream input(argv[1], std::ios::in | std::ios::binary);
    if(!input) throw std::ios::failure("Error opening file!");

    auto result = getScore( input );

    std::cout << "Score: " << result << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
