#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <boost/asio.hpp>
// #include <boost/array.hpp>

#include "DataPacket.hh"

class dataHandler {
    public: 
    dataHandler() = default;

    dataPacket readFile(const std::string& filename) {
        dataPacket packet;

        std::ifstream file(filename, std::ios::binary);

        if (file.is_open()) {
            packet.data = std::vector<char>((std::istreambuf_iterator<char>(file)),
                                           (std::istreambuf_iterator<char>()));

            packet.size = static_cast<std::uint32_t>(packet.data.size()); 
            packet.type = 0; // Тип данных: файл
            return packet;
        }

        throw std::runtime_error("Ошибка открытия файла: " + filename);
    }

    void writeFile(const dataPacket& packet, const std::string& filename) {
        std::ofstream file(filename, std::ios::binary);

        if (file.is_open()) {
            file.write(packet.data.data(), packet.data.size());
        }
        else {
            throw std::runtime_error("Ошибка открытия файла: " + filename);
        }
    }

    boost::asio::const_buffer packData(const dataPacket& packet) {
        std::vector<char> buffer(sizeof(packet.size) + sizeof(packet.type) + packet.size);
        char* ptr = buffer.data();

        memcpy(ptr, &packet.size, sizeof(packet.size));
        ptr += sizeof(packet.size);

        memcpy(ptr, &packet.type, sizeof(packet.type));
        ptr += sizeof(packet.type);

        memcpy(ptr, packet.data.data(), packet.data.size());

        return boost::asio::buffer(buffer);
    }

    dataPacket unpackData(const std::vector<char>& buffer) {
        dataPacket packet;
        auto ptr = buffer.data();

        memcpy(&packet.size, ptr, sizeof(packet.size));
        ptr += sizeof(packet.size);

        memcpy(&packet.type, ptr, sizeof(packet.type));
        ptr += sizeof(packet.type);

        packet.data.assign(ptr, ptr + packet.size);

        return packet;
    }
};