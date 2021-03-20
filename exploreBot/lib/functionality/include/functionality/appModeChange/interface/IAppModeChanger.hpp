#ifndef IAPPMODECHANGER_H
#define IAPPMODECHANGER_H

#include "functionality/appModeChange/interface/IAppModeChangeObserver.hpp"

#include <string>

namespace ExploreBot::Lib::Functionalities::AppModeChange {

class IAppModeChanger
{
public:
    virtual ~IAppModeChanger() = default;

    virtual bool addObserver(AppModeChangeObserverPtr observer) noexcept = 0;
    [[nodiscard]] virtual bool changeMode(std::string_view modeName) noexcept = 0;
};

}   // namespace ExploreBot::Lib::Functionalities::AppModeChange

#endif   // IAPPMODECHANGER_H
