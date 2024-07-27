// вызывает из DataHandler readFile(filename) - возврат dataPacket;
// вызов packData(dataPacket) - вщзврат boost::asio::const_buffer
// sendData() - свой метод - передача по tcp
// 
#include "Connection.hh"
#include "DataPacket.hh"

#include <boost/asio.hpp>

using namespace boost::asio;

class Sender{
 private:
    io_context& io_context_;
    ip::tcp::socket socket_;
    ip::tcp::endpoint receiver_endpoint_;

 public:
    Sender(io_context& io_context, const std::string& ip_address, unsigned short port): 
    io_context_(io_context),
    socket_(io_context, ip::tcp::endpoint(ip::address::from_string(ip_address), port)) {
        std::cout << "I'm OK" ;
    };


    // dataPacket& transfer() { 
    //     return;
    // };
};