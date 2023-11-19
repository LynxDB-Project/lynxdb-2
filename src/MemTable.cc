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

#include "MemTable.h"

namespace LynxDB {
    MemTable::MemTable(int maxCapacity)
        : _maxCapacity(maxCapacity)
        , _skipList(new SkipList) {}

    MemTable::~MemTable() { delete _skipList; }

    bool MemTable::full() { return _skipList->size() == _maxCapacity; }

    void MemTable::insert(const Bytes& key, const Bytes& value) { _skipList->insert(key, value); }

    void MemTable::remove(const Bytes& key) { _skipList->remove(key); }

    Bytes MemTable::find(const Bytes& key) { return _skipList->find(key); }

    void MemTable::rangeBefore(const Bytes& begin, int limit,
                               std::unordered_map<Bytes, Bytes>& findPairs,
                               std::unordered_set<Bytes>& deletedKeys) {
        _skipList->rangeBefore(begin, limit, findPairs, deletedKeys);
    }
    void MemTable::rangeNext(const Bytes& begin, int limit,
                             std::unordered_map<Bytes, Bytes>& findPairs,
                             std::unordered_set<Bytes>& deletedKeys) {
        _skipList->rangeNext(begin, limit, findPairs, deletedKeys);
    }
}// namespace LynxDB