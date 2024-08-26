#pragma once

#include <string> 

struct KeyValue {
    std::string key;
    std::string value;

    KeyValue(const std::string &key, const std::string &value) : key(key), value(value) {}
};