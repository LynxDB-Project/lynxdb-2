//
// Created by Baili Zhang on 2023/10/18.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Copyright (c) 2023 Baili Zhang All rights reserved.
//

#ifndef LYNXDB_MEMTABLE_H
#define LYNXDB_MEMTABLE_H

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Bytes.h"
#include "SkipList.h"

namespace LynxDB {

    class MemTable {
    private:
        int _maxCapacity;
        SkipList* _skipList;

    public:
        MemTable() = delete;
        explicit MemTable(int maxCapacity);
        ~MemTable();

        bool full();
        void insert(const Bytes& key, const Bytes& value);
        void remove(const Bytes& key);
        LynxDB::Bytes find(const Bytes& key);

        void rangeBefore(const Bytes& begin, int limit, std::unordered_map<Bytes, Bytes>& findPairs,
                         std::unordered_set<Bytes>& deletedKeys);

        void rangeNext(const Bytes& begin, int limit, std::unordered_map<Bytes, Bytes>& findPairs,
                       std::unordered_set<Bytes>& deletedKeys);
    };

}// namespace LynxDB

#endif//LYNXDB_MEMTABLE_H
