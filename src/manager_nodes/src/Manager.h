#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <memory>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Callback.h"

class Callback;

class Manager{

private:

    typedef std::shared_ptr<Callback> CallbackPtr;
    ros::NodeHandle n;
    ros::Publisher publisher;
    std::vector<CallbackPtr> callbacks;

    CallbackPtr get_callback_by_topic(std::string topic);

public:

    Manager(std::string topic, int queue_length);

    void publish(std::string s);

    void subscribe(std::string topic, int queue_length);

    std::string callback(const std::string topic);

    void cycle();

    ros::NodeHandle nodehandle() const;

};

#endif /* MANAGER_H */
