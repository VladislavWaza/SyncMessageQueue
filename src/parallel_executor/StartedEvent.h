#ifndef STARTEDEVENT_H
#define STARTEDEVENT_H

#include "DeviceEvent.h"

/*!
 * \brief Класс ивента начала работы устройства
*/
class StartedEvent : public DeviceEvent
{
public:
  StartedEvent(std::shared_ptr<Device> device);
  std::string toString() const override;
};

#endif
