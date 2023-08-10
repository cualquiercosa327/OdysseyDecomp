#pragma once

#include "al/Library/HostIO/HioNode.h"
#include "al/Library/Nerve/IUseNerve.h"

namespace al {
class Nerve;
class NerveKeeper;

class NerveExecutor : public IUseNerve, public HioNode {
public:
    NerveExecutor(const char* name);

    virtual NerveKeeper* getNerveKeeper() const;
    virtual ~NerveExecutor();

    void initNerve(const Nerve* nerve, int stateCount);
    void updateNerve();

private:
    NerveKeeper* mKeeper = nullptr;
};
};  // namespace al
