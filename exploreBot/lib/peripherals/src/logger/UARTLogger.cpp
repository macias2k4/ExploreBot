#include "peripherals/logger/UARTLogger.hpp"

using namespace std;

namespace ExploreBot::Lib::Peripherals::Logger {

static constexpr auto infoPrefix { "<I> " };
static constexpr auto debugPrefix { "<D> " };
static constexpr auto warningPrefix { "<W> " };
static constexpr auto errorPrefix { "<E> " };

static constexpr uint32_t numberOfMSecInOneSec { 1000 };

UARTLogger::UARTLogger(UART_HandleTypeDef& uart)
    : _uart { uart }
    , _bytesToTransferAtOneSec { _uart.Init.BaudRate / 10 }
{}

void UARTLogger::info(const std::string& msg) const noexcept { transmitMessage(string { infoPrefix }.append(msg)); }

void UARTLogger::debug(const string& msg) const noexcept { transmitMessage(string { debugPrefix }.append(msg)); }

void UARTLogger::warning(const string& msg) const noexcept { transmitMessage(string { warningPrefix }.append(msg)); }

void UARTLogger::error(const string& msg) const noexcept { transmitMessage(string { errorPrefix }.append(msg)); }

void UARTLogger::transmitMessage(string& msg) const noexcept
{
    msg.append("\r\n");
    const uint32_t timeout = ((msg.size() * numberOfMSecInOneSec) / _bytesToTransferAtOneSec) * 2;
    HAL_UART_Transmit(&_uart, reinterpret_cast<uint8_t*>(msg.data()), static_cast<uint16_t>(msg.size() + 1), timeout);
}

}   // namespace ExploreBot::Lib::Peripherals::Logger
