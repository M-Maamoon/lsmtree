#include <vector>

#include "helpers/keyvalue.hpp"
#include "tree/lsmtree.hpp"
int main() {
    std::vector<KeyValue> kvs;
    for (int i = 0; i < 100000; i++) {
        kvs.push_back(KeyValue("key" + std::to_string(i), "value" + std::to_string(i)));
    }
    
    LsmTree lsmTree;
    for (int i = 0; i < 100000; i++) {
        lsmTree.insert(kvs[i]);
    }
    return 0;
}