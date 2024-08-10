#ifndef EVENT_H
#define EVENT_H

#include <string>

/*!
 * \brief Абстрактный класс ивента
*/
class Event
{
public:
  virtual ~Event() {}

  /*!
   * \brief Возвращает сообщение, соответствующее событию.
   *
   * \return Строка, которая содержит информацию о событии.
  */
  virtual std::string toString() const = 0;
};

#endif
