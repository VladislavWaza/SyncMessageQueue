#ifndef DATAEVENT_H
#define DATAEVENT_H

#include "DeviceEvent.h"

/*!
 * \brief Класс ивента передачи данных
*/
class DataEvent : public DeviceEvent
{
public:
  DataEvent(std::shared_ptr<Device> device);
  std::string toString() const override;
};

#endif
