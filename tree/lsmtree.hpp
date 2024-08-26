#pragma once

#include "../buffermanager/BufferManager.hpp"
#include "../helpers/keyvalue.hpp"
class LsmTree {
   public:
    LsmTree();
    ~LsmTree();
    void insert(KeyValue &kv);
    void remove(const std::string key);
    std::string get(const std::string key);

   private:
    BufferManager bm;
};
