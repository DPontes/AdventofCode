#ifndef RATINGS_H
#define RATINGS_H

#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <fstream>
#include "helpers.h"

using matrix = std::vector<std::vector<int>>;

std::vector<int> getCommonVector(const matrix&, const std::string);

std::vector<int> getReading(const matrix&, const std::string&, int);

int getRating(const matrix&, const std::string&, const int&);

std::pair<int ,int> getRatings(matrix&);

matrix readValuesIntoMatrix(std::ifstream&);

int lifeSupportRating(std::ifstream&);

#endif
