#include "Parser.h"
#include "DeviceA.h"
#include "DeviceB.h"

#include <boost/program_options.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
  try
  {
    size_t loopCountA;
    size_t loopCountB;
    size_t crushIndexA;
    size_t crushIndexB;

    boost::program_options::options_description desc{"Allowed options"};
    desc.add_options()
        ("help", "produce help message")
        ("loopCountA", boost::program_options::value<size_t>(&loopCountA)->default_value(10), "number of reading iterations from device A")
        ("loopCountB", boost::program_options::value<size_t>(&loopCountB)->default_value(3), "number of reading iterations from device B")
        ("crushIndexA", boost::program_options::value<size_t>(&crushIndexA)->default_value(10), "an integer indicating at what iteration device A will break down")
        ("crushIndexB", boost::program_options::value<size_t>(&crushIndexB)->default_value(3), "an integer indicating at what iteration device B will break down")
    ;

    boost::program_options::variables_map varMap;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), varMap);
    boost::program_options::notify(varMap);

    if(varMap.count("help"))
    {
      std::cout << desc << "\n";
      return 1;
    }

    std::cout << "loopCountA was set to " << loopCountA << "\n";
    std::cout << "loopCountB was set to " << loopCountB << "\n";
    std::cout << "crushIndexA was set to " << crushIndexA << "\n";
    std::cout << "crushIndexB was set to " << crushIndexB << "\n";

    Parser parser(std::make_shared<EventQueue>(), std::make_shared<DeviceA>(), std::make_shared<DeviceB>());
    parser.run(loopCountA, loopCountB, crushIndexA, crushIndexB);
  }
  catch(std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }
  return 0;
}