
#include "utils.hpp"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

void connect_client(ip::tcp::socket& socket){
    socket.connect(
        tcp::endpoint(
            address::from_string("127.0.0.1"),
            9999
        )
    );
}