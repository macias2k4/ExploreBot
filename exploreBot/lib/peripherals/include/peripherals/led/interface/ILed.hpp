#ifndef ILED_H
#define ILED_H

namespace ExploreBot::Lib::Peripherals::Led {

class ILed
{
public:
    virtual ~ILed() = default;

    virtual void turnOn() noexcept = 0;
    virtual void turnOff() noexcept = 0;
};

}   // namespace ExploreBot::Lib::Peripherals::Led

#endif   // ILED_H
