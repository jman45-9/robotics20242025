#ifndef ROBOT_ROBOTICS2425_HPP
#define ROBOT_ROBOTICS2425_HPP
#include "api.h"
#include "lemlib/api.hpp"
#include "config_macros.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"

namespace highstakes {
class Robot {
         private:
                pros::MotorGroup leftmtrgroup;
                pros::MotorGroup rightmtrgroup;
                lemlib::Drivetrain drivetrain;

                pros::Rotation rot_hor;
                pros::Rotation rot_ver;
                lemlib::TrackingWheel hor_tracking;
                lemlib::TrackingWheel ver_tracking;
                pros::IMU imu;
                lemlib::OdomSensors odom_sensors;

                lemlib::ControllerSettings lateralpid;
                lemlib::ControllerSettings angularpid;

                pros::Motor intake;
                pros::adi::DigitalOut clamp;


                bool clampState = LOW;
        public:
                lemlib::Chassis chassis;

                Robot();
                void TankInput(double leftY, double rightY);
                void clampToggle();
                void intakeRun();
                void intakeExtake();
                void intakeBrake();


};
}
#endif // ROBOT_ROBOTICS2425_HPP
