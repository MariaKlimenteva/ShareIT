#include <iostream>
#include <boost/asio.hpp>
#include <array>

using boost::asio::ip::udp;
namespace asio = boost::asio;

int main()
{
    try
    {
        asio::io_service io_service;

        udp::socket socket(io_service);
        socket.open(asio::ip::udp::v4());
        socket.bind(udp::endpoint(asio::ip::address_v4::any(), 7777));

        std::array<char, 128> recv_buffer;

        while (true)
        {
            udp::endpoint sender_endpoint;
            size_t len = socket.receive_from(asio::buffer(recv_buffer), sender_endpoint);

            // Проверяем, соответствует ли полученное сообщение запросу "*IDN?;"
            if (std::string(recv_buffer.begin(), recv_buffer.begin() + len) == "*IDN?;")
            {
                std::cout << "Received IDN request from: " << sender_endpoint << std::endl;

                // Отправляем ответ
                const std::string response = "My ID is: TEST_DEVICE";
                socket.send_to(asio::buffer(response), sender_endpoint); 
                std::cout << "Sent response: " << response << std::endl;
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}