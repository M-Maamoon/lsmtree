#include "memtable.hpp"

#include <string>

#include "../helpers/keyvalue.hpp"
std::string Memtable::get(const std::string &key) {
    auto it = mem_table.find(key);
    if (mem_table.find(key) != mem_table.end()) {
        return it->second;
    }
    return "";
}

void Memtable::put(KeyValue &kv) {
    mem_table[kv.key] = kv.value;
}

void Memtable::remove(const std::string &key) {
    mem_table.erase(key);
}

bool Memtable::isFull() {
    return mem_table.size() == MAX_SIZE;
}
