#include "StartedEvent.h"
#include "WorkDoneEvent.h"
#include "DataEvent.h"

DeviceEvent::DeviceEvent(std::shared_ptr<Device> device)
  : m_device(device) 
{
}

StartedEvent::StartedEvent(std::shared_ptr<Device> device)
  : DeviceEvent(device)
{ 
}

WorkDoneEvent::WorkDoneEvent(std::shared_ptr<Device> device)
  : DeviceEvent(device)
{ 
}

DataEvent::DataEvent(std::shared_ptr<Device> device)
  : DeviceEvent(device)
{ 
}

std::string DeviceEvent::toString() const
{
  return m_device->getName();
}

std::string StartedEvent::toString() const
{
  return "Started " + DeviceEvent::toString();
}

std::string WorkDoneEvent::toString() const
{
  return "Finished " + DeviceEvent::toString();
}

std::string DataEvent::toString() const
{
  return m_device->getDataAsString() + " from " + DeviceEvent::toString();
}