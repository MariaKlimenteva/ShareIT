#pragma once

#include <vector>

class Connection {
    public:
    Connection() = default;
    
    virtual std::vector<char> transfer() = 0;
};

