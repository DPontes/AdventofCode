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
