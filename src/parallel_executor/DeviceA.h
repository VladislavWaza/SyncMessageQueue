#ifndef DEVICEA_H
#define DEVICEA_H

#include "Device.h"

/*!
 * \brief Класс устройства A
*/
class DeviceA : public Device
{
public:
  std::string getName() const override;
  std::string getDataAsString() const override;
};

#endif
