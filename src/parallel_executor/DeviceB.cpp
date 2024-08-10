#include "DeviceB.h"

#include <cstdlib>
#include <ctime>

std::string DeviceB::getName() const
{
  return "B";
}

std::string DeviceB::getDataAsString() const
{
  std::srand(std::time(nullptr));
  std::string result;
  const int max_val = 198;
  const int min_val = 0;
  result += std::to_string(std::rand() % (max_val - min_val + 1) + min_val) + ' ';
  result += std::to_string(std::rand() % (max_val - min_val + 1) + min_val) + ' ';
  result += std::to_string(std::rand() % (max_val - min_val + 1) + min_val);
  return result;
}