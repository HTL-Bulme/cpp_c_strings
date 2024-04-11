#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <cstdint>

using std::size_t;

int64_t sum(int32_t array[], size_t count);
int64_t product(int32_t array[], size_t count);
int32_t min(int32_t array[], size_t count);
int32_t max(int32_t array[], size_t count);
size_t count(int32_t array[], size_t count_, int32_t val);

#endif  // ARRAY_HPP
