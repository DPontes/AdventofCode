#include <iostream>
#include <fstream>

int isDeeper(int a, int b)
{
  return b > a;
}

int main(int argc, char **argv)
{
  std::string depth;
  std::fstream input ("./input");
  int previous = -1;
  int counter = 0;

  if (input.is_open())
  {
    while (getline(input, depth))
    {
      int depth_n = std::stoi(depth);
      if(previous == -1)
      {
        previous = depth_n;
      }
      else
      {
        if(isDeeper(previous, depth_n)) counter++;
        previous = depth_n;
      }
    }
    input.close();
  }
  else
  {
    std::cout << "Unable to open file" << std::endl;
  }

  std::cout << "Total: " << counter << std::endl;

  return 0;
}
