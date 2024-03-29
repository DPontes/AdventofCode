# Advent of Code 2021

[Link](https://adventofcode.com/2021/)

## Day 1

### Part 1

- In order to find the solution for the amount of times the depth increases (`totalDepthIncrements`), the implementation reads through the input file with a `getline()` function. Each element `depth` is compared to the `previous` element (except for the first one, where `previous = -1`) in `isDeeper(a, b)`. If `depth > input`, then `totalDepthIncrements` is incremented by (1).

- The implementation checks for input which isn't a number:

```
    try
    {
        depth = std::stoi(sDepth);
    }
    catch (std::invalid_argument& e)
    {
    ...
```

  as well as if the `input` file fails to open:

```
    if(!input) throw std::ios::failure("Error opening file!");
```

### Part 2

- The implementation changed the main function `countTotalDepthIncrements(std::ifstream&)` to include vector `depths` that would be populated with `emplace_back()` for every new element `depth` (as long as this wasn't NaN, otherwise the program would throw an exception and exit).
  For each of the new elements in `depths` (and the size of `depths` > 3) the function `sumsPrevAndDepth(std::vector<int>) returns a pair of 2 sums:

    - sumPrevious: depths[n-1] + depths[n-2] + depths[n-3]
    - sumCurrent:  depths[n]   + depths[n-1] + depths[n-2]

    given that `n` is the last element of vector `depths`.
    These 2 sums are compared (`isHigher(const int*, const int*)` and if `sumCurrent` is bigger than `sumPrevious`, then `totalDepthIncrements` is incremented by 1.
    The idea to run the operation for every input `depths` is to keep the time complexity of this solution being `O(n)`

## Day 2

### Part 1

- The solution to this challenge reads a stream of instructions `instr` from the `input` file, with the format `'action' 'size'` and parses these into the variables `std::string action` and `std::string size` respectively.
  The input `action` is of type `string` and can be `{up, down, forward}` and `size` is of type `int` and is a non-negative integer. These are fed into the appropriate function `actionUp/Down/Forward` according to the content of `action`.
  The above function(s) call passes the `coord` pair and `size` as reference, and changes the value of the `first` item of `coord` if the `action` is `up/down` and the second if it´s `forward`.
  When the `input` is finished, the `first` and `second` items of `coord` are multiplied together and returned.
  *Possible improvements*:
  - Generalize the `actionUp/Down/Forward()` functions into one
  - Use a tuple instead of a pair in order to be easier to expand the amount of items

### Part 2

- The pair used in Part 1 was transformed into a tuple in order to use the same application flow with minimal alterations. Adding the `aim` as a 3rd argument in the tuple allowed for keeping the coordinates and the name close together.
  The functions `actionUp/Down/Forward` were changed to accomodate for the required changes, where:
  - `actionUp` decreases the `aim`
  - `actionDown` increases the `aim`
  - `actionForward` increases the horizontal and changes the depth as a product of the `aim` x `size`

## Day 3

### Part 1

#### Note: I'm currently not really happy with how "hacky" this solution is, but it works

- To see what is most common (0 or 1) for each column of the `input`, each line `binaryString` is parsed into `int`s of `[0, 1]`, where each of its elements' value is added to the existing value of `binaryVector`. With the total sum for each element, if said element is bigger than `nReads / 2` it means that `1` was more common at that element, otherwise it was `0`.

  with this operation it is possible then to determine `gammaRate` and `epsilonRate` which are the decimal versions of the binary number obtained from the most common values for each element of `binaryVector`, and its "mirror" (e.g.: `100101` is the "mirror" of `011010`)

### Part 2

- The main implementation is visible in the `ratings.cpp` file. A `helpers.cpp` file is also created that includes useful functions not directly related to the calculation of the O2 and CO2 ratings.

  Initially the `readValuesIntoMatrix(std::ifstream&)` will just read the `ifstream` into a `binaryString` which will then be added into a matrix of size `N x M`, where:
  - `N` is the number of columns in the matrix
  - `M` is the number of lines in the matrix

  in function `appendVectorToMatrix(std::vector<std::vector<int>>, std::string)`.

  The Life Support Ratings of O2 and CO2 are obtained through the `getRating(matrix&, const std::string&, const int&)` function. This function takes in the original matrix with all the readings, as well as the `rule` which defines if the rating will be obtained for the O2 or CO2 by indicating if it will look for the `most` or the `less` (or least) common value of [0, 1] for each column of the `matrix`, respectively.

  The rating is achieved by transforming into a decinal the binary vector (`binaryVector2Decimal(std::vectorzint>)`) obtained in the `getReading(const matrix&, const std::String&, int)` function.

  The `getReading(...)` function is a recursive function, as in it calls itself during operation while a specific condition occurs. In this case, it will call itself while the `index` value is less or equal to `N`, i.e., the number of columns of the matrix.
  
  It starts by obtaining a `commonVector` vector which contains the most/least common values [0, 1] for each column, depending on the `rule`. It checks next if the number of lines of the `internalMatrix` passed by reference is 1. If that's the case, it will stop reading and return as `rating` the rest of the elements in the `[index:]` interval. On the other hand, if the number of lines is > 1, it will check which lines in the `internalMatrix` have the most common element in the `index` and add those to a temporary `newMatrix` matrix.

  Finally, the process starts again, if the `index` is smaller than `N`, the number of columns in the matrix. If, however, it reached the end, it will return the final `rating`.

  
