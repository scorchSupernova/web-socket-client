#include <boost/asio.hpp>
#include <iostream>

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
    io_service new_io_service;
    tcp::acceptor acceptor_part(new_io_service, tcp::endpoint(tcp::v4(), 9999));
    tcp::socket soc_obj(new_io_service);

    acceptor_part.accept(soc_obj);

    string u_name = receiveData(soc_obj);
    u_name.pop_back();


    string resp, reply = "Oye " + u_name + ".";
    cout<<"Server: "<<reply<<endl;

    sendData(soc_obj, reply);

    while(true) {
        resp = receiveData(soc_obj);
        resp.pop_back();
        if(resp == "exit"){
            cout<<u_name<<" left..."<<endl;
        }
        cout<<u_name<<" "<<resp<<endl;
        cout<<"Server: ";
        getline(cin, reply);
        sendData(soc_obj, reply);

        if (reply == "exit") break;
    }

    return 0;


}