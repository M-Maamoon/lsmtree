#pragma once

#include <map>
#include <string>

#include "../helpers/keyvalue.hpp"
class Memtable {
   public:
    std::string get(const std::string &key);
    void put(KeyValue &kv);
    void remove(const std::string &key);
    bool isFull();
    std::map<std::string, std::string> mem_table;

   private:
    long unsigned int MAX_SIZE = 1000;
};