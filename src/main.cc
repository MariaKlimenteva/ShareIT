#include <iostream>
// #include <boost/array.hpp>
#include "Sender.hh"
#include "Reciever.hh"
#include "mainwindow.h"

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);
//     QTextEdit textEdit;
//     textEdit.show();

//     MainWindow w;
//     w.show();
    
//     return app.exec();
// }
#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QTextEdit textEdit;
    QPushButton quitButton("Quit");

    /* 10 */ QObject::connect(&quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    /* 12 */ QVBoxLayout layout;
    /* 13 */ layout.addWidget(&textEdit);
    /* 14 */ layout.addWidget(&quitButton);

    QWidget window;
    /* 17 */ window.setLayout(&layout);

    window.show();

    return app.exec();
}

// int main() {
//     boost::asio::io_context io_context;
//   // Создаем экземпляры отправителя и получателя
//     Sender sender(io_context, "127.0.0.1", 5000);
//     Receiver receiver(io_context, 6000);

//     // Устанавливаем адреса и порты
//     sender.setReceiver("127.0.0.1", 6000);

//     // Устанавливаем соединение
//     sender.connect();

//     // Принимаем соединение
//     receiver.acceptConnection();

//     // Создаем буфер данных
//     std::string data = "Hello from sender!";
//     boost::asio::const_buffer buffer(data.data(), data.size());

//     // Отправка данных
//     sender.sendData(buffer);

//     // Получение данных
//     std::vector<char> received_data(data.size());
//     boost::asio::mutable_buffer receive_buffer(received_data.data(), received_data.size());
//     std::size_t bytes_received = receiver.receiveData(receive_buffer);

//     std::cout << "Received data: " << std::string(received_data.begin(), received_data.begin() + bytes_received) << std::endl;

//     io_context.run();
//     return 0;
// }