#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <math.h>
#include <string>
#include <vector>

using matrix = std::vector<std::vector<int>>;

int convertCharToInt(const char&);

float getPower(const int&, const float&);

int binaryVector2Decimal(const std::vector<int>&);

std::vector<int> appendString2Vector(const std::string&);

void appendVectorToMatrix(matrix&, const std::string&);


#endif
