#pragma once

#include <vector>
#include "DataPacket.hh"

class Connection {
    public:
    Connection() = default;
    
    virtual dataPacket& transfer() = 0;
};

