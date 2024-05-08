#include <boost/asio.hpp>
#include <iostream>
#include "utils.hpp"
using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;


string receiveData(tcp::socket& socket){
    boost::asio::streambuf newbuf;
    read_until(socket, newbuf, "\n");
    string data = buffer_cast<const char*>(newbuf.data());
    return data;
}

void sendData(tcp::socket& socket, const string& message){
    write(socket, buffer(message + "\n"));
}

int main(){
    io_service client_io_service;
    ip::tcp::socket client_soc_obj(client_io_service);

    UTILS_HPP::connect_client(client_soc_obj);
    

    cout<<"Your name: "<<endl;
    string u_name, reply, response;
    getline(cin, u_name);

    sendData(client_soc_obj, u_name);
    while(true){
        response = receiveData(client_soc_obj);
        response.pop_back();

        if(response == "exit") {
            cout<<"Connection terminated\n";
            break;
        }
        cout<<"Server: "<<response<<endl;
        getline(cin, reply);
        sendData(client_soc_obj, reply);

        if(reply == "exit") break;
    }
    return 0;
}