#include <sstream>
#include <iostream>
#include <exception>
#include <fstream>

void actionUp(std::pair<int, int> &p, const std::string &size)
{
  p.first -= std::stoi(size);
}

void actionDown(std::pair<int, int> &p, const std::string &size)
{
  p.first += std::stoi(size);
}

void actionForward(std::pair<int, int> &p, const std::string &size)
{
  p.second += std::stoi(size);
}

const int multiplyDepthHorizontal(std::ifstream& input)
{
  std::string instr;
  std::string action;
  std::string size;
  std::pair coord = {0, 0};     // c++17 syntax

  while(getline(input, instr))
  {
    std::istringstream linestream(instr);
    linestream >> action >> size;

    if( action == "up")      actionUp      (coord, size);
    if( action == "down")    actionDown    (coord, size);
    if( action == "forward") actionForward (coord, size);
  }

  return coord.first * coord.second;

}

int main(int argc, char *argv[])
{

  try
  {
    std::ifstream input(argv[1], std::ios::in | std::ios::binary);
    if(!input) throw std::ios::failure("Error opening file!");

    std::cout << "Depth x Horizontal: " << multiplyDepthHorizontal( input ) << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
