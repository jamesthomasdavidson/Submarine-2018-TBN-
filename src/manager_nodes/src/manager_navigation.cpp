#include "Manager.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "navigation_manager");
    Manager navigation_manager = Manager("sub1", 1000);
    navigation_manager.subscribe("sub1", 100);
    navigation_manager.subscribe("sub2", 100);
    ros::Rate loop_rate(1);
    while(ros::ok()){
        navigation_manager.publish("anyone there?");
        loop_rate.sleep();
        navigation_manager.cycle();
        std::cout<<navigation_manager.callback("sub1")<<std::endl;
        std::cout<<navigation_manager.callback("sub2")<<std::endl;
    }
    return 0;
}
