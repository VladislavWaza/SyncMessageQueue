#include "DeviceA.h"
#include "DeviceB.h"

#include <gtest/gtest.h>

TEST(DeviceA, GetNameTest)
{
  DeviceA device;
  ASSERT_EQ(device.getName(), "A");
}

TEST(DeviceB, GetNameTest)
{
  DeviceB device;
  ASSERT_EQ(device.getName(), "B");
}