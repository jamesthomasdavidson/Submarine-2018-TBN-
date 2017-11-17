#include "Manager.h"

Manager::CallbackPtr Manager::get_callback_by_topic(std::string topic){
    for(int i = 0; i < callbacks.size(); i++){
        if(callbacks.at(i)->topic() == topic){
            return callbacks.at(i);
        }
    }
    return callbacks.at(0);
}

Manager::Manager(std::string topic, int queue_length){
    publisher = n.advertise<std_msgs::String>(topic, queue_length);
}

void Manager::publish(std::string s){
    std_msgs::String msg;
    msg.data = s;
    publisher.publish(msg);
}

void Manager::subscribe(std::string topic, int queue_length){
    auto p = std::make_shared<Callback>(topic, queue_length, this);
    callbacks.push_back(p);
}

std::string Manager::callback(const std::string topic){
    CallbackPtr cb = get_callback_by_topic(topic);
    std::string str = cb->data();
    return str;
}

void Manager::cycle(){
    ros::spinOnce();
}

ros::NodeHandle Manager::nodehandle() const{
    return n;
}
