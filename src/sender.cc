#include <iostream>
#include <boost/asio.hpp>
#include <array>

using boost::asio::ip::udp;
namespace asio = boost::asio;

const char* idnMsg = "*IDN?;";

int main(int argc, char* argv[])
{
    try
    {
        asio::io_service serv;

        boost::system::error_code err;

        udp::socket socket(serv);
        socket.open(asio::ip::udp::v4(), err);
        if (!err)
        {
            socket.set_option(udp::socket::reuse_address(true));
            socket.set_option(asio::socket_base::broadcast(true));

            asio::ip::udp::endpoint senderEndpoint(asio::ip::address_v4::broadcast(), 7777);

            socket.send_to(asio::buffer(idnMsg, 6), senderEndpoint);
            //socket.close(err);

            std::array<char, 128> buf;

            while (socket.available())
            {
                asio::ip::udp::endpoint remote;

                size_t len = socket.receive_from(asio::buffer(buf), remote);

                std::cout << "Received: ";
                std::cout.write(buf.data(), len);

                buf.fill(0);
            }
        }
        else
            std::cerr << "Error connecting: " << err.message() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}