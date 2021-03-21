#ifndef IAPPMODE_HPP
#define IAPPMODE_HPP

#include <vector>
#include <string>
#include <memory>

namespace ExploreBot::Lib::Functionalities::AppMode {

class IAppMode
{
public:
    virtual ~IAppMode() = default;

    virtual std::string modeName() const noexcept = 0;
    virtual void executeStep() noexcept = 0;
};

using AppModePtr = std::shared_ptr<IAppMode>;
using AppModePtrVector = std::vector<AppModePtr>;

}   // namespace ExploreBot::Lib::Functionalities::AppMode

#endif   // IAPPMODE_HPP
