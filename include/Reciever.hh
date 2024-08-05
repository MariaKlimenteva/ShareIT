#include "DataPacket.hh"

#include <boost/asio.hpp>

class Receiver {
 private:
    boost::asio::ip::tcp::acceptor acceptor_;
    boost::asio::io_context& io_context_;
    boost::asio::ip::tcp::socket socket_;

 public:
    Receiver(boost::asio::io_context& io_context, unsigned short port): io_context_(io_context),
    acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)), socket_(io_context) {}

    std::size_t receiveData(boost::asio::mutable_buffer buffer) {
        return boost::asio::read(socket_, buffer);
    }

    void acceptConnection() {
        acceptor_.accept(socket_);
    }
};