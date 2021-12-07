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
  The input `action is of type `string` and can be `{up, down, forward}` and `size` is of type `int` and is a non-negative integer. These are fed into the appropriate function `actionUp/Down/Forward` according to the content of `action`.
  The above function(s) call passes the `coord` pair and `size` as reference, and changes the value of the `first` item of `coord` if the `action` is `up/down` and the second if it´s `forward`.
  When the `input` is finished, the `first` and `second` items of `coord` are multiplied together and returned.
  *Possible improvements*:
  - Generalize the `actionUp/Down/Forward()` functions into one
  - Use a tuple instead of a pair in order to be easier to expand the amount of items
