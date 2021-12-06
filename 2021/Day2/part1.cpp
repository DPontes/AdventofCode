#include <sstream>
#include <iostream>
#include <exception>
#include <fstream>

const int multiplyDepthHorizontal(std::ifstream& input)
{
  std::string instr;
  std::string action;
  std::string size;
  auto p = std::make_pair(0, 0);
  while(getline(input, instr))
  {
    std::istringstream linestream(instr);
    linestream >> action >> size;

    if( action == "up")      p.first -= std::stoi(size);
    if( action == "down")    p.first += std::stoi(size);
    if( action == "forward") p.second += std::stoi(size);
  }
  return p.first * p.second;
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
