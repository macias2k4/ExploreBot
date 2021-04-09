#ifndef UARTLOGGER_HPP
#define UARTLOGGER_HPP

#include "peripherals/logger/interface/ILogger.hpp"

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_uart.h>

#include <string>

namespace ExploreBot::Lib::Peripherals::Logger {

class UARTLogger final : public ILogger
{
public:
    explicit UARTLogger(UART_HandleTypeDef& uart);

    void info(const std::string& msg) const noexcept override;
    void debug(const std::string& msg) const noexcept override;
    void warning(const std::string& msg) const noexcept override;
    void error(const std::string& msg) const noexcept override;

private:
    UART_HandleTypeDef& _uart;
    uint32_t _bytesToTransferAtOneSec { 0 };

    void transmitMessage(std::string& msg) const noexcept;
};

}   // namespace ExploreBot::Lib::Peripherals::Logger

#endif   // UARTLOGGER_HPP
