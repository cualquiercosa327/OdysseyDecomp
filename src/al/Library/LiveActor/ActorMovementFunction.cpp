#include <math/seadVector.h>
#include "al/Library/LiveActor/ActorPoseKeeper.h"
#include "al/Library/LiveActor/LiveActorUtil.h"
#include "al/Library/Math/MathUtil.h"

namespace al {

float calcDistance(const al::LiveActor* l1, const al::LiveActor* l2) {
    return calcDistance(l1, getTrans(l2));
}

float calcDistance(const al::LiveActor* l1, const sead::Vector3f& vec) {
    sead::Vector3f distance = al::getTrans(l1) - vec;
    return distance.length();
}

float calcSpeed(const al::LiveActor* actor) {
    return actor->getPoseKeeper()->getVelocity().length();
}

float calcSpeedH(const al::LiveActor* actor) {
    sead::Vector3f verticalized;
    al::verticalizeVec(&verticalized, al::getGravity(actor), actor->getPoseKeeper()->getVelocity());
    return verticalized.length();
}

float calcSpeedV(const al::LiveActor* actor) {
    return -actor->getPoseKeeper()->getVelocity().dot(al::getGravity(actor));
}

}  // namespace al
