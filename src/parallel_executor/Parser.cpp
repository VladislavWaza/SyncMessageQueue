#include "Parser.h"
#include "StartedEvent.h"
#include "DataEvent.h"
#include "WorkDoneEvent.h"

#include <iostream>
#include <thread>

Parser::Parser(std::shared_ptr<EventQueue> queue, std::shared_ptr<Device> deviceA, std::shared_ptr<Device> deviceB)
  : m_queue(queue), m_deviceA(deviceA), m_deviceB(deviceB)
{
  if (m_queue.get() == nullptr || m_deviceA.get() == nullptr || m_deviceB.get() == nullptr)
    throw std::runtime_error("nullptr received");
}

void Parser::run(size_t loopCountA, size_t loopCountB, size_t crushIndexA, size_t crushIndexB)
{
  std::thread readA(&Parser::read, this, m_deviceA, std::chrono::seconds(1), loopCountA, crushIndexA);
  std::thread readB(&Parser::read, this, m_deviceB, std::chrono::seconds(5), loopCountB, crushIndexB);

  size_t activeDevice = 2;
  while (activeDevice > 0)
  {
    auto event = m_queue->pop(std::chrono::seconds(6));
    if (event.get() != nullptr)
    {
      std::cout << event->toString() << '\n';

      if (dynamic_cast<const WorkDoneEvent*>(event.get()) != nullptr)
      {
        --activeDevice;
      }
    }
    else
    {
      --activeDevice;
    }
  }

  readA.join();
  readB.join();
}

void Parser::read(std::shared_ptr<Device> device, std::chrono::seconds sleepDuration, size_t loopCount, size_t crushIndex)
{
  try
  {
    std::shared_ptr<const Event> event(std::make_shared<StartedEvent>(device));
    m_queue->push(event);
    for (size_t i = 0; i < loopCount; ++i)
    {
      if (i == crushIndex)
      {
        return;
      }
      event = std::make_shared<DataEvent>(device);
      std::this_thread::sleep_for(sleepDuration);
      m_queue->push(event);
    }
    event = std::make_shared<WorkDoneEvent>(device);
    m_queue->push(event);
  }
  catch(std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }
  catch(...)
  {
    std::cerr << "Caught unknown exception\n";
  }
}