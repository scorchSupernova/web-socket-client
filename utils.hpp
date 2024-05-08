#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <boost/asio.hpp>

void connect_client(boost::asio::ip::tcp::socket& socket);

#endif