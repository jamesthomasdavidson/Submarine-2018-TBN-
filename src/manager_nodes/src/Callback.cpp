#include "Callback.h"

Callback::Callback(std::string topic, int queue_length, const Manager *manager){
    t = topic;
    m = manager;
    s = m->nodehandle().subscribe(topic, queue_length, &Callback::callback, this);
}

void Callback::callback(const std_msgs::String::ConstPtr& msg){
    std::string str = "";
    str = msg->data;
    d = str;
}

std::string Callback::topic() const{
    return t;
}

std::string Callback::data(){
    return d;
}
