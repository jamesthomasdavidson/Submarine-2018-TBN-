#ifndef CALLBACK_H
#define CALLBACK_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Manager.h"

#define TRUE 1
#define FALSE 0
#define MAX_MSG_SIZE 200

class Manager;

class Callback{

    ros::Subscriber s;
    const Manager *m;
    std::string t;
    std::string d;

    void callback(const std_msgs::String::ConstPtr& msg);

public:

    Callback(std::string topic, int queue_length, const Manager *manager);
    ~Callback(){
        std::cout << "In ~Callback" << std::endl;
    }
    std::string topic() const;

    std::string data();
};

#endif /* CALLBACK_H */
