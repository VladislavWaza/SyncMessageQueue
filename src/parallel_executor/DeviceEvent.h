#ifndef DEVICEEVENT_H
#define DEVICEEVENT_H

#include "Event.h"
#include "Device.h"

#include <memory>

/*!
 * \brief Абстрактный класс ивента от устройства
*/
class DeviceEvent : public Event
{
public:
  /*!
   * \brief Конструктор. Необходим для заполнения информации об устройстве.
  */
  DeviceEvent(std::shared_ptr<Device> device);
  std::string toString() const override = 0;

protected:
  std::shared_ptr<Device> m_device;
};

#endif
