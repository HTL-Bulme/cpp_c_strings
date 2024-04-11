# Introductory C++ Exercises - Part 2

To make sure your code can compile, please add all the required declarations
to `array.hpp` (see the descriptions of task 2 and 3).

Please do not look up pre-made solutions for these tasks as writing them
yourself will help you later on.

Compile your code via

```shell
mkdir build -p && cd build
cmake ..
make -j8  # use 8 processor cores when compiling
```

Execute the tests via

```shell
build/array_test
```

## Task 1 - `max`, `min`, `product` and `sum`
The task is to implement the following functions

* `int64_t sum(int32_t array[], std::size_t count)`: add all values
* `int64_t product(int32_t array[], std::size_t count)`: multiply all values
* `int32_t min(int32_t array[], std::size_t count)`: find the smallest value
* `int32_t max(int32_t array[], std::size_t count)`: find the largest value
* `std::size_t count(int32_t array[], std::size_t count_, int32_t val)`
   return how many times `val` is in the array

You may assume that the arrays passed to min and max have at least one element.
If an empty array is passed to `sum`, return 0. If an empty array is passed to
`product`, return 1.

Write your code in `array.cpp`.

### Test Cases
Remember that you may run individual tests by passing additional arguments
to the test runner. For example

```shell
./array_test --help
./array_test --list-tests  # list all available tests
./array_test [sum]
./array_test [multiply] --section "corner cases"
```

## Task 2 - Statistics
Extend the file from the previous task with basic statistics over the passed
arrays. To do so, implement the following functions:

* `double mean(int32_t array[], size_t count)`: calculate the mean (average)
* `double variance(int32_t array[], size_t count)`

`variance(.)` must return the sample variance of the data in the array:

$$
\frac{\sum_{i=i}^n (x_i - \mu)^2}{n - 1}
$$

You may assume that input arrays contains at least one element for `mean(.)`
and at least two elements for `variance(.)`.

Add their declaration also to the header file `array.hpp`.

Write your code in `array.cpp`.


## Task 3 - Subarray
Given an array, two indices and a second array, fill the second
array from the beginning with the elements from the first array
between the given indices.
Include the element at the first index, exclude the element at the second
index. Declare your function as

```cpp
void subarray(int32_t array[], size_t start, size_t end,
              int32_t target[]);
```

For example

```cpp
int32_t array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int32_t target[3];
subarray(array, 2, 5, target)  // target should become { 3, 4, 5 }
```

You may assume that <code>target</code> is always large enough to hold the
elements written to it.

Write your code in `array.cpp`.
