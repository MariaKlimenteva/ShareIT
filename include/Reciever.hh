// receiveData() - вернет std::vector<char> - трансфер
// unpackData() класса DataHandler - передает std::vector<char> - возвращает объект DataPacket
// writeFile() класса DataHandler, передавая DataPacket и имя файла для сохранения
// DataHandler записывает данные из DataPacket в файл
#include "Connection.hh"
#include "DataPacket.hh"
#include "DataHandler.hh"

class Reciever: public Connection {
    public:
    std::vector<char> transfer() {

    }
    void saveData() {
        dataHandler data;
        data.unpackData();
        data.writeFile();
        return 
    }


};