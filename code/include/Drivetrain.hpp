#ifndef DRIVETRAIN_HEADER_Y2425_HPP
#define DRIVETRAIN_HEADER_Y2425_HPP

#include "api.h"
using namespace pros;
using namespace pros::literals;

#define MTR_FAST E_MOTOR_GEAR_BLUE
#define DRI_REV 0

namespace Y2425
{
class Drivetrain
{
        public:
                Imu inertial;                
                Motor LBMtr;
                Motor LCMtr;
                Motor LFMtr;
                Motor RBMtr;
                Motor RCMtr;
                Motor RFMtr;

                Drivetrain();
                void leftDrive(int mV);
                void rightDrive(int mV);
};
}

#endif //DRIVETRAIN_HEADER_Y2425_HPP
