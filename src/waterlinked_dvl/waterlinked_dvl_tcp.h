#ifndef WATERLINKED_DVL_TCP_H
#define WATERLINKED_DVL_TCP_H

#include "ros/ros.h"
#include "boost/asio.hpp"
#include "boost/thread.hpp"
#include "thread"

class WaterlinkedDvlTcp {
private:

    ros::NodeHandle m_nh;
    ros::NodeHandle m_pnh;

    boost::asio::io_service m_io_service;
    boost::asio::ip::tcp::socket m_socket;


    std::string m_ip;
    int m_port;

    void f_readloop();

    void f_parse_and_publish(std::string incoming);

    boost::thread m_reading_thread;

    ros::Publisher m_transducer_publisher;

    ros::Publisher m_position_publisher;

public:

    WaterlinkedDvlTcp();

};


#endif
