#include "BufferManager.hpp"
#include <algorithm>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>

#include "../tables/sstable.hpp"

BufferManager::BufferManager() {
    const char *ssTablePath = getenv("SSTABLE_BLOCK") ? getenv("SSTABLE_BLOCK") : "/tmp/sst";
    ssTablesBlockFd = open(ssTablePath, O_RDWR | O_DIRECT, S_IRWXU);
    if (ssTablesBlockFd == -1) {
        std::cerr << "cannot open BLOCK device for the SSTable '" << ssTablePath << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void BufferManager::flushSStableToDisk() {
    SSTable sstable;
    
}

void BufferManager::flushMemtable() {
    SSTable sstable =  translateToSSTable();
    writeToDisk(sstable);
    memtable.mem_table.clear();
}

SSTable BufferManager::translateToSSTable() {
    std::vector<std::string> tableContent;
    for (auto &kv : memtable.mem_table) {
        tableContent.push_back(kv.first + " " + kv.second + "\n");
    }
    std::sort(tableContent.begin(), tableContent.end());
    return tableContent;
}

void BufferManager::writeToDisk(SSTable &sstable) {
    std::string ssTable = sstable.getTableContent();
    std::cout << "Writing to disk sstable number: " << sstables.size() << " in location " << sstables.size() * SSTABLE_BLOCK_SIZE << std::endl;  
    pwrite(ssTablesBlockFd, ssTable.c_str(), SSTABLE_BLOCK_SIZE, sstables.size() * SSTABLE_BLOCK_SIZE);
    levels[0].push_back(&sstable);
    sstables.push_back(&sstable);
}