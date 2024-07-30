#include "../include/Drivetrain.hpp"
Y2425::Drivetrain::Drivetrain() :
        inertial(1),
        LBMtr(2),
        LCMtr(3),
        LFMtr(4),
        RBMtr(5),
        RCMtr(6),
        RFMtr(7)
{
}

void Y2425::Drivetrain::leftDrive(int mV)
{
        this->LBMtr.move_voltage(mV);
        this->LCMtr.move_voltage(mV);
        this->LFMtr.move_voltage(mV);
}

void Y2425::Drivetrain::rightDrive(int mV)
{
        this->RBMtr.move_voltage(mV);
        this->RCMtr.move_voltage(mV);
        this->RFMtr.move_voltage(mV);
}
