#include <sstream>
#include <iostream>
#include <exception>
#include <fstream>
#include <tuple>

void actionUp(std::tuple<int, int, int> &t, const std::string &size)
{
  std::get<2>(t) -= std::stoi(size);
}

void actionDown(std::tuple<int, int, int> &t, const std::string &size)
{
  std::get<2>(t) += std::stoi(size);
}

void actionForward(std::tuple<int, int, int> &t, const std::string &size)
{
  std::get<0>(t) += std::stoi(size);
  std::get<1>(t) += std::stoi(size) * std::get<2>(t);
}

const int multiplyDepthHorizontal(std::ifstream& input)
{
  std::string instr;
  std::string action;
  std::string size;
  std::tuple<int, int, int> coord {0, 0, 0};

  while(getline(input, instr))
  {
    std::istringstream linestream(instr);
    linestream >> action >> size;

    if( action == "up")      actionUp      (coord, size);
    if( action == "down")    actionDown    (coord, size);
    if( action == "forward") actionForward (coord, size);
  }

  return std::get<0>(coord) * std::get<1>(coord);

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
