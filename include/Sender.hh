#include "DataPacket.hh"

#include <boost/asio.hpp>

using namespace boost::asio;

class Sender{
 private:
    io_context& io_context_;
    ip::tcp::socket socket_;
    ip::tcp::endpoint receiver_endpoint_;

 public:
    Sender(io_context& io_context): io_context_(io_context), socket_(io_context) {}

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

    std::vector<std::string> findReceivers(std::string network_address, int start_port, int end_port) {
        std::vector<std::string> receivers;
        ip::address base_address = ip::address::from_string(network_address);

        for (int i = start_port; i <= end_port; ++i) {
            ip::tcp::endpoint endpoint(base_address, i);
            
            try {
                ip::tcp::socket socket(io_context_, ip::tcp::v4());
                socket.connect(endpoint);
                receivers.push_back(base_address.to_string());
            } catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
        }

        return receivers;
    }
};