#include "DeviceA.h"

#include <cstdlib>
#include <ctime>

std::string DeviceA::getName() const
{
  return "A";
}

std::string DeviceA::getDataAsString() const
{
  std::srand(std::time(nullptr));
  std::string result;
  const int max_val = 500;
  const int min_val = 0;
  int size = std::rand() % (max_val - min_val + 1) + min_val;

  const int codeA = 'a';
  const int codeZ = 'z';
  for(int i = 0; i < size; ++i)
  {
    result += std::rand() % (codeZ - codeA + 1) + codeA;
  }
  return result;
}