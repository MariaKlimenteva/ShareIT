#include <iostream>
#include <boost/array.hpp>
#include "Sender.hh"
#include "Reciever.hh"

using namespace boost::asio;

int main() {
    io_context io;
    Sender client_1(io, "127.0.0.1", 8080);
    // client_1.transfer();

    return 0;
}