#ifndef CONFIG_MACROS_HIGHSTAKES_HPP
#define CONFIG_MACROS_HIGHSTAKES_HPP

#include "api.h"
#include "lemlib/api.hpp"
#include "../helper_functions/helper_fuctions.hpp"
namespace highstakes 
{
namespace config 
{
// smart port constants
// const int <name> = <port_num>;
const int DRIVE_FRONT_LEFT = 1;
const int DRIVE_MID_LEFT = 2;
const int DRIVE_BACK_LEFT = 3;

const int DRIVE_FRONT_RIGHT = 4;
const int DRIVE_MID_RIGHT = 5;
const int DRIVE_BACK_RIGHT = 6;

const int IMU = 7;
const int ODOM_ROT_VER = 8;
const int ODOM_ROT_HOR = 9;

// threewire port constants
// const char <name> = <port_letter>

// robot drive specs
const double DRIVE_WHEEL_DIAM = lemlib::Omniwheel::NEW_325; //(in)
const double WHEELBASE = 1; //(in)
const double TRACK_WIDTH = 10; //(in)
const int DRIVE_GEAR = pros::E_MOTOR_GEAR_BLUE;
const double DRIVE_HORIZONTAL_DRIFT = 2;
const double DRIVE_RPM = 600;

//odom dimensions
const double TRACKING_WHEEL_DIAM = lemlib::Omniwheel::OLD_275;
const double ODOM_VER_OFFSET = 1;
const double ODOM_HOR_OFFSET = -1;

} // namsespace config
} // namespace highstakes

#endif //CONFIG_MACROS_HIGHSTAKES_HPP
