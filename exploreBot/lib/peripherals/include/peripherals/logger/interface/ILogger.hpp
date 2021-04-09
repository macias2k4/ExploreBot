#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <string>

namespace ExploreBot::Lib::Peripherals::Logger {

class ILogger
{
public:
    virtual ~ILogger() = default;

    virtual void info(const std::string& msg) const noexcept = 0;
    virtual void debug(const std::string& msg) const noexcept = 0;
    virtual void warning(const std::string& msg) const noexcept = 0;
    virtual void error(const std::string& msg) const noexcept = 0;
};

}   // namespace ExploreBot::Lib::Peripherals::Logger

#endif   // ILOGGER_HPP
