#pragma once
#include <map>
#include <string>
#include <vector>

#include "../helpers/keyvalue.hpp"
class SSTable {
   public:
    SSTable(std::map<std::string, std::string> &table);
    SSTable(std::vector<std::string> &table);
    SSTable();
    ~SSTable();
    // std::string find(const std::string key);
    std::string getTableContent();

   private:
    std::vector<std::string> tableContent;
};