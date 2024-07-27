#include <iostream>
// #include <boost/array.hpp>
#include "Sender.hh"
#include "Reciever.hh"

int main() {
    boost::asio::io_context io_context;
  // Создаем экземпляры отправителя и получателя
    Sender sender(io_context, "127.0.0.1", 5000);
    Receiver receiver(io_context, 6000);

    // Устанавливаем адреса и порты
    sender.setReceiver("127.0.0.1", 6000);

    // Устанавливаем соединение
    sender.connect();

    // Принимаем соединение
    receiver.acceptConnection();

    // Создаем буфер данных
    std::string data = "Hello from sender!";
    boost::asio::const_buffer buffer(data.data(), data.size());

    // Отправка данных
    sender.sendData(buffer);

    // Получение данных
    std::vector<char> received_data(data.size());
    boost::asio::mutable_buffer receive_buffer(received_data.data(), received_data.size());
    std::size_t bytes_received = receiver.receiveData(receive_buffer);

    std::cout << "Received data: " << std::string(received_data.begin(), received_data.begin() + bytes_received) << std::endl;

    io_context.run();
    return 0;
}