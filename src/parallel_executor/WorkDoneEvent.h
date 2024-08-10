#ifndef WORKDONEEVENT_H
#define WORKDONEEVENT_H

#include "DeviceEvent.h"

/*!
 * \brief Класс ивента успешного завершения работы устройства
*/
class WorkDoneEvent : public DeviceEvent
{
public:
  WorkDoneEvent(std::shared_ptr<Device> device);
  std::string toString() const override;
};

#endif
