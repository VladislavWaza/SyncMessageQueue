#ifndef PARSER_H
#define PARSER_H

#include "EventQueue.h"
#include "Device.h"

class Parser
{
public:
  /*!
   * \brief Конструктор
   *
   * \param[in] queue Умный указатель на очередь.
   * \param[in] deviceA Умный указатель на устройство A.
   * \param[in] deviceB Умный указатель на устройство B.
  */
  Parser(std::shared_ptr<EventQueue> queue, std::shared_ptr<Device> deviceA, std::shared_ptr<Device> deviceB);

  /*!
   * \brief Функция, запускающая чтение данных с устройств в параллельном режиме.
   *
   * \param[in] loopCountA Беззнаковое целое число, задающее кол-во итераций чтения с устройства А.
   * \param[in] loopCountB Беззнаковое целое число, задающее кол-во итераций чтения с устройства В.
   * \param[in] crushIndexA Целое число, указывающая на какой итерации сломается устройство А.
   * \param[in] crushIndexB Целое число, указывающая на какой итерации сломается устройство B.
  */
  void run(size_t loopCountA, size_t loopCountB, size_t crushIndexA = SIZE_MAX, size_t crushIndexB = SIZE_MAX);

private:
  /*!
   * \brief Читает данные с устройства.
   *
   * \param[in] device Умный указатель на устройство
   * \param[in] sleepDuration Секунды, задающие длительность прерывания для симулированной работы.
   * \param[in] loopCount Беззнаковое целое число, задающее кол-во итераций чтения с устройства.
   * \param[in] crushIndex Целое число, указывающая на какой итерации сломается устройство.
  */
  void read(std::shared_ptr<Device> device, std::chrono::seconds sleepDuration, size_t loopCount, size_t crushIndex);

private:
  std::shared_ptr<EventQueue> m_queue;
  std::shared_ptr<Device> m_deviceA;
  std::shared_ptr<Device> m_deviceB;
};

#endif
