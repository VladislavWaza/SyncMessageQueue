#include "EventQueue.h"

#include "DeviceA.h"
#include "DeviceB.h"

#include "Parser.h"

#include <gtest/gtest.h>

#include <memory>

namespace
{
  std::string captureOutput(std::function<void()> func)
  {
    std::stringstream buffer;
    using BasicStreambuf = std::basic_streambuf<char, std::char_traits<char>>;
    std::unique_ptr<BasicStreambuf> old {std::cout.rdbuf(buffer.rdbuf())};
    func();
    std::cout.rdbuf(old.release());
    return buffer.str();
  }
}

TEST(Parser, RunDefaultTest)
{
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  Parser parser(queue, A, B);

  std::string stream = captureOutput([&]() { parser.run(1, 1); });

  EXPECT_TRUE(stream.find("Started A") != std::string::npos);
  EXPECT_TRUE(stream.find(" from A") != std::string::npos);
  EXPECT_TRUE(stream.find("Finished A") != std::string::npos);

  EXPECT_TRUE(stream.find("Started B") != std::string::npos);
  EXPECT_TRUE(stream.find(" from B") != std::string::npos);
  EXPECT_TRUE(stream.find("Finished B") != std::string::npos);
}

TEST(Parser, RunCrushATest)
{
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  Parser parser(queue, A, B);

  std::string stream = captureOutput([&]() { parser.run(2, 1, 1); });

  EXPECT_TRUE(stream.find("Started A") != std::string::npos);
  EXPECT_TRUE(stream.find(" from A") != std::string::npos);
  EXPECT_TRUE(stream.find("Finished A") == std::string::npos);

  EXPECT_TRUE(stream.find("Started B") != std::string::npos);
  EXPECT_TRUE(stream.find(" from B") != std::string::npos);
  EXPECT_TRUE(stream.find("Finished B") != std::string::npos);
}

TEST(Parser, RunCrushBTest)
{
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  Parser parser(queue, A, B);

  std::string stream = captureOutput([&]() { parser.run(1, 2, 1, 1); });

  EXPECT_TRUE(stream.find("Started A") != std::string::npos);
  EXPECT_TRUE(stream.find(" from A") != std::string::npos);
  EXPECT_TRUE(stream.find("Finished A") != std::string::npos);

  EXPECT_TRUE(stream.find("Started B") != std::string::npos);
  EXPECT_TRUE(stream.find(" from B") != std::string::npos);
  EXPECT_TRUE(stream.find("Finished B") == std::string::npos);
}

TEST(Parser, RunCrushABTest)
{
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  Parser parser(queue, A, B);

  std::string stream = captureOutput([&]() { parser.run(2, 2, 1, 1); });

  EXPECT_TRUE(stream.find("Started A") != std::string::npos);
  EXPECT_TRUE(stream.find(" from A") != std::string::npos);
  EXPECT_TRUE(stream.find("Finished A") == std::string::npos);

  EXPECT_TRUE(stream.find("Started B") != std::string::npos);
  EXPECT_TRUE(stream.find(" from B") != std::string::npos);
  EXPECT_TRUE(stream.find("Finished B") == std::string::npos);
}

TEST(Parser, InitWithEmptyQueueTest)
{
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  EXPECT_THROW(
    Parser(nullptr, std::move(A), std::move(B)),
    std::runtime_error
  );
}

TEST(Parser, InitWithEmptyDevicesTest)
{
  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
  std::shared_ptr<Device> A = std::make_shared<DeviceA>();
  std::shared_ptr<Device> B = std::make_shared<DeviceB>();

  EXPECT_THROW(
    Parser(queue, nullptr, std::move(B)),
    std::runtime_error
  );

  EXPECT_THROW(
    Parser(queue, std::move(A), nullptr),
    std::runtime_error
  );
}
