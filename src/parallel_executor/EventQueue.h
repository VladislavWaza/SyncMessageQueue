#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include "Event.h"

#include <memory>
#include <chrono>

#include <queue>

#include <mutex>
#include <condition_variable>

/*!
 * \brief Потокобезопасный класс очереди сообщений
*/
class EventQueue
{
public:
  /*!
   * \brief Положить сообщение в очередь  
  */
  void push(const std::shared_ptr<const Event> & event);

  /*!
   * \brief Удалить сообщение из очереди и вернуть его
   *
   * Если по истечении времени очередь пуста, возвращает пустой указатель
   * 
   * \param[in] duration Время ожидания если очередь пуста
   * 
   * \return Сообщение из очереди
  */
  std::shared_ptr<const Event> pop(const std::chrono::seconds & duration);

private:
  std::queue<std::shared_ptr<const Event>> m_queue;
  std::mutex m_mutex;
  std::condition_variable m_cv;
};

#endif
