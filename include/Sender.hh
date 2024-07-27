// вызывает из DataHandler readFile(filename) - возврат dataPacket;
// вызов packData(dataPacket) - вщзврат boost::asio::const_buffer
// sendData() - свой метод - передача по tcp
// 
#include "Connection.hh"
#include "DataPacket.hh"
#include "DataHandler.hh"

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

    // void sendData(dataPacket& packet) {
    //     auto filename = packet.filename;
    //     dataHandler data;
    //     auto packet = data.readFile(filename);
    //     boost::asio::const_buffer asio_buf = data.packData(packet);

    //     boost::asio::write(socket_, asio_buf);
    // };
    void sendData(const boost::asio::const_buffer& buffer) {
        boost::asio::write(socket_, buffer);
    }

    void setReceiver(const std::string& ip_address, unsigned short port) {
        receiver_endpoint_.address(boost::asio::ip::address::from_string(ip_address));
        receiver_endpoint_.port(port);
    };

    void connect() {
        socket_.connect(receiver_endpoint_);
    }

};