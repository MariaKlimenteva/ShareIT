#include "DataHandler.hh"
#include "gtest/gtest.h"

TEST(DataHandlerTest, PackUnpackData) {
    dataHandler data_handler;
    dataPacket packet;
    packet.size = 10;
    packet.type = 0;
    packet.data = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!' };

    boost::asio::const_buffer buffer = data_handler.packData(packet);

    // Извлекаем данные из буфера
    std::vector<char> buffer_data(buffer.size());
    std::copy(buffer.data(), buffer.data() + buffer.size(), buffer_data.begin());

    dataPacket unpacked_packet = data_handler.unpackData(buffer_data);

    // Проверка совпадения данных
    ASSERT_EQ(unpacked_packet.size, packet.size);
    ASSERT_EQ(unpacked_packet.type, packet.type);
    ASSERT_EQ(unpacked_packet.data, packet.data);
}

TEST(DataHandlerTest, ReadWriteFile) {
    dataHandler data_handler;
    std::string filename = "test_file.txt";
    std::string content = "Hello, world!";

    // Запись в файл
    dataPacket packet;
    packet.size = content.size();
    packet.type = 1; // Тип: текст
    packet.data.assign(content.begin(), content.end());
    data_handler.writeFile(packet, filename);

    // Чтение из файла
    dataPacket read_packet = data_handler.readFile(filename);

    // Проверка
    ASSERT_EQ(read_packet.size, content.size());
    ASSERT_EQ(read_packet.type, 1);
    ASSERT_EQ(std::string(read_packet.data.begin(), read_packet.data.end()), content);
}