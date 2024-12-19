#ifndef ROBOT_ROBOTICS2425_HPP
#define ROBOT_ROBOTICS2425_HPP
#include "api.h"
#include "lemlib/api.hpp"
#include "config_macros.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "helpers.hpp"

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
                pros::adi::DigitalOut doinker;

                pros::adi::DigitalIn clamp_lmit_1;
                pros::adi::DigitalIn clamp_lmit_2;



                bool clampState = LOW;
                bool doinking = LOW;
                bool intakeState = false;

                int clampTimeout = 0;
        public:
                lemlib::Chassis chassis;

                Robot();
                void init();

                bool getIntakeState();

                void TankInput(double leftY, double rightY);
                void clampToggle();
                void doinkToggle();
                void intakeRun();
                void intakeExtake();
                void intakeBrake();
                void brake();
                void toggleIntake();
                void checkClamp();

                void timeoutClamp();
                void decClampTimeout();
                bool clampInTimeout();
                        
                pros::Motor track;

                void mov(double direc);
                void turn(double direc);
                double getInertial();

};
}
#endif // ROBOT_ROBOTICS2425_HPP
