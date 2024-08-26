#include "sstable.hpp"

#include <algorithm>
#include <sstream>

SSTable::SSTable(std::map<std::string, std::string> &table) {
    for (auto &kv : table) {
        this->tableContent.push_back(kv.first + " " + kv.second + "\n");
    }
    std::sort(this->tableContent.begin(), this->tableContent.end());
}

SSTable::SSTable(std::vector<std::string> &table) : tableContent(table) {}

SSTable::SSTable() {}

std::string SSTable::getTableContent() {
    std::stringstream ss;
    for (auto &kv : this->tableContent) {
        ss << kv << std::endl;
    }
    return ss.str();
}

SSTable::~SSTable() {
    this->tableContent.clear();
}
