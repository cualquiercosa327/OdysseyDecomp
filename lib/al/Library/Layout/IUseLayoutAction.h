#pragma once

#include "al/Library/HostIO/IUseName.h"

namespace al {
class LayoutActionKeeper;

class IUseLayoutAction : virtual public IUseName {
public:
    virtual LayoutActionKeeper* getLayoutActionKeeper() const = 0;
};
}
