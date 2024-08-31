#include "../include/Robot.hpp"

highstakes::Robot::Robot():
leftmtrgroup(
                {
                highstakes::config::DRIVE_FRONT_LEFT, 
                highstakes::config::DRIVE_MID_LEFT,
                highstakes::config::DRIVE_BACK_LEFT
                }
            ),
rightmtrgroup(
                {
                highstakes::config::DRIVE_FRONT_RIGHT,
                highstakes::config::DRIVE_MID_RIGHT,
                highstakes::config::DRIVE_BACK_RIGHT
                }
             ),
drivetrain(
                &(this->leftmtrgroup),
                &(this->rightmtrgroup),
                highstakes::config::TRACK_WIDTH,
                highstakes::config::DRIVE_WHEEL_DIAM,
                highstakes::config::DRIVE_RPM,
                highstakes::config::DRIVE_HORIZONTAL_DRIFT
          ),
rot_hor(highstakes::config::ODOM_ROT_HOR),
rot_ver(highstakes::config::ODOM_ROT_VER),
hor_tracking(
                &(this->rot_hor),
                highstakes::config::TRACKING_WHEEL_DIAM,
                highstakes::config::ODOM_HOR_OFFSET
            ),
ver_tracking(
                &(this->rot_ver),
                highstakes::config::TRACKING_WHEEL_DIAM,
                highstakes::config::ODOM_VER_OFFSET
            ),
imu(highstakes::config::IMU),
odom_sensors(
                &(this->ver_tracking),
                nullptr,
                &(this->hor_tracking),
                nullptr,
                &(imu)
            ),
lateralpid(
                10, //kp
                0, //ki
                3, //kd
                3, //anti windup
                1, // small err range in inches
                100, //small err range timeout in mil-sec
                3, //large err range in inches
                500, // large err timeout in mil-sec
                20 // max accleration (slew)
        ),
angularpid(
                2, //kp
                10, //ki
                0, //kd
                3, //anti windup
                1, // small err range in degrees
                100, //small err range timeout in mil-sec
                3, //large err range in inches
                500, // large err timeout in mil-sec
                0 // max accleration (slew)
        ),
clamp (
                highstakes::config::ADI_CLAMP_PORT,
                LOW
      ),
chassis(
                this->drivetrain,
                this->lateralpid,
                this->angularpid,
                this->odom_sensors
       )
{
}

void highstakes::Robot::TankInput(double leftY, double rightY) 
{
        this->chassis.tank(leftY, rightY);
}

void highstakes::Robot::clampToggle()
{
        this->clampState = !this->clampState;
        this->clamp.set_value(this->clampState);
}
