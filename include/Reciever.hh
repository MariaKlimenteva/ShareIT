// receiveData() - вернет std::vector<char> - трансфер

// Пусть transfer возвращает dataPacket

// unpackData() класса DataHandler - передает std::vector<char> - возвращает объект DataPacket
// writeFile() класса DataHandler, передавая DataPacket и имя файла для сохранения
// DataHandler записывает данные из DataPacket в файл
#include "Connection.hh"
#include "DataPacket.hh"
#include "DataHandler.hh"

class Reciever {
    private:
    boost::asio::ip::tcp::acceptor acceptor_;

    public:
    // dataPacket& transfer() {
    //     return ;
    // };

    void saveData(const dataPacket& packet) {
        const std::vector<char>& buffer = packet.data;

        dataHandler data;
        data.unpackData(buffer);
        data.writeFile(packet, packet.filename); 
    }


};