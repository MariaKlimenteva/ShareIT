// #include "Connection.hh"
#include "DataPacket.hh"
// #include "DataHandler.hh"

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
    socket_(io_context, ip::tcp::endpoint(ip::address::from_string(ip_address), port)) {}

    void sendData(const boost::asio::const_buffer& buffer) {
        boost::asio::write(socket_, buffer);
    }

    void setReceiver(const std::string& ip_address, unsigned short port) {
        receiver_endpoint_.address(boost::asio::ip::address::from_string(ip_address));
        receiver_endpoint_.port(port);
    }

    void connect() {
        socket_.connect(receiver_endpoint_);
    }

};