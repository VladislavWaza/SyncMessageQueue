#ifndef DEVICE_H
#define DEVICE_H

#include <string>

/*!
 * \brief Абстрактный класс устройства
*/
class Device
{
public:
  virtual ~Device() {}

  /*!
   * \brief Возвращает имя, соответствующее устройству.
   *
   * \return Строка. Имя устройства.
  */
  virtual std::string getName() const = 0;

  /*!
   * \brief Симулирует чтение данных.
   *
   * \return Строка. Прочитанные данные.
  */
  virtual std::string getDataAsString() const = 0;
};

#endif
