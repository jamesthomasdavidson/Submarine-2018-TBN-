#include "Manager.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "info_manager");
    Manager info_manager = Manager("sub2", 1000);
    ros::Rate loop_rate(1);
    while(ros::ok()){
        info_manager.publish("SUP");
        info_manager.cycle();
        loop_rate.sleep();
    }
    return 0;
}
