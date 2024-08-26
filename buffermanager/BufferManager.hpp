#pragma once

#include <map>
#include <string>
#include <vector>

#include "../tables/memtable.hpp"
#include "../tables/sstable.hpp"
class BufferManager {
   public:
    BufferManager();
    void flushMemtable();
    void flushSStableToDisk();
    Memtable memtable;

   private:
    void writeToDisk(SSTable &sstable);
    SSTable translateToSSTable();
    int sstablesBlockFd;
    static const int SSTABLE_BLOCK_SIZE = 4096;
    std::vector<SSTable *> sstables;
    std::vector<std::vector<SSTable *>> levels;
    int ssTablesBlockFd;
};