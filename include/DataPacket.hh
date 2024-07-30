#pragma once

#include <cstdint>
#include <vector>
#include <boost/asio.hpp>

struct dataPacket {
    // std::uint32_t size; 
    // std::uint8_t type; 
    std::vector<char> data;
    // std::string filename;
};