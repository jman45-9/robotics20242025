#include "../include/auton.hpp"
void highstakes::selTest(void *robotVessel) 
{
        Robot *robot = (Robot *)robotVessel;
        robot->track.move_voltage(12*1000);
}

void highstakes::selTest2(void *robotVessel)
{
        Robot *robot = (Robot *)robotVessel;
        robot->track.move_voltage(-12*1000);
}
