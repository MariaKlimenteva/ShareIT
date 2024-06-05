#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

int main() {
  try {
    boost::asio::io_context io_context;
    udp::socket socket(io_context, udp::v4());

    udp::endpoint broadcast_endpoint(
        boost::asio::ip::address::from_string("255.255.255.255"), 8888); 

    std::string message = "Shareit: Find Devices";

    // Отправка UDP-пакета с помощью async_send_to
    socket.async_send_to(
        
        boost::asio::buffer(message),
        broadcast_endpoint,
        [](const boost::system::error_code& error, std::size_t bytes_sent) {
          if (error) {
            std::cerr << "Ошибка отправки: " << error.message() << std::endl;
          } else {
            std::cout << "Отправлено " << bytes_sent << " байт" << std::endl;
          }
        });

    io_context.run();

  } catch (std::exception& e) {
    std::cerr << "Ошибка: " << e.what() << std::endl;
  }
  return 0;
}