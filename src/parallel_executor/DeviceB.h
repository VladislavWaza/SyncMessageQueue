#ifndef DEVICEB_H
#define DEVICEB_H

#include "Device.h"

/*!
 * \brief Класс устройства B
*/
class DeviceB : public Device
{
public:
  std::string getName() const override;
  std::string getDataAsString() const override;
};

#endif
