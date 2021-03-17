#ifndef IAPPMODECHANGER_H
#define IAPPMODECHANGER_H

#include <string>

namespace ExploreBot::Lib::Functionalities::AppModeChange {

class IAppModeChanger
{
public:
    virtual ~IAppModeChanger() = default;

    [[nodiscard]] virtual bool changeMode(std::string_view modeName) const noexcept = 0;
};

}

#endif // IAPPMODECHANGER_H
