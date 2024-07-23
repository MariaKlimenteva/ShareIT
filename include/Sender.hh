// вызывает из DataHandler readFile(filename) - возврат dataPacket;
// вызов packData(dataPacket) - вщзврат boost::asio::const_buffer
// sendData() - свой метод - передача по tcp
// 
#include "Connection.hh"
#include "DataPacket.hh"

class Sender: public Connection {
    
    public:
    std::vector<char> transfer() {
        boost::asio::const_buffer packData(dataPacket& msg);
    }
    bool sendData() {

    }

};