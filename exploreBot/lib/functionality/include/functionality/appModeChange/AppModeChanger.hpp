#ifndef APPMODECHANGER_HPP
#define APPMODECHANGER_HPP

#include "functionality/appModeChange/interface/IAppModeChanger.hpp"

namespace ExploreBot::Lib::Functionalities::AppModeChange {

class AppModeChanger final : public IAppModeChanger
{
public:

    [[nodiscard]] bool changeMode(std::string_view modeName) const noexcept override;
};

}

#endif // APPMODECHANGER_HPP
