#include "AutoPostRightSwitch.h"

namespace PostRightSwitchTrajectories {

extern const unsigned int kTrajectoryLength;
extern const robovikes::TrajectoryPoint leftTrajectories[];
extern const robovikes::TrajectoryPoint rightTrajectories[];

}

static const int kPointDurationMillis = 10;

AutoPostRightSwitch::AutoPostRightSwitch()
: ChassisMotionProfileCommand(
    PostRightSwitchTrajectories::leftTrajectories,
    PostRightSwitchTrajectories::rightTrajectories,
    PostRightSwitchTrajectories::kTrajectoryLength,
    kPointDurationMillis)
{
}


