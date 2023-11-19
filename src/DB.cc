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

#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>

#include "DB.h"

namespace LynxDB {
    DB::DB(const std::filesystem::path& dbPath)
        : _mutable(new MemTable(DEFAULT_MEMTABLE_SIZE))
        , _immutable(nullptr)
        , _levelTree(new LevelTree(dbPath)) {}

    DB::~DB() {
        delete _mutable;
        delete _immutable;
        delete _levelTree;
    }

    void DB::insert(const Bytes& key, const Bytes& value) {
        if (_mutable->full()) {
            MemTable* needMerge = _immutable;
            _immutable = _mutable;
            _mutable = new MemTable(DEFAULT_MEMTABLE_SIZE);
            _levelTree->merge(needMerge);
        }

        _mutable->insert(key, value);
    }

    Bytes DB::find(const Bytes& key) {
        LynxDB::Bytes value = _mutable->find(key);
        if (!value.empty()) { return value; }

        value = _immutable->find(key);
        if (!value.empty()) { return value; }

        return _levelTree->find(key);
    }

    void DB::remove(const Bytes& key) {
        if (_mutable->full()) {
            MemTable* needMerge = _immutable;
            _immutable = _mutable;
            _mutable = new MemTable(DEFAULT_MEMTABLE_SIZE);
            _levelTree->merge(needMerge);
        }

        _mutable->remove(key);
    }

    std::vector<std::pair<Bytes, Bytes>> DB::rangeBefore(const Bytes& begin, int limit) {
        std::unordered_map<Bytes, Bytes> findPairs;
        std::unordered_set<Bytes> deletedKeys;

        _mutable->rangeBefore(begin, limit, findPairs, deletedKeys);
        _immutable->rangeBefore(begin, limit, findPairs, deletedKeys);
        _levelTree->rangeBefore(begin, limit, findPairs, deletedKeys);

        std::vector<std::pair<Bytes, Bytes>> pairs;
        for (auto pair: findPairs) { pairs.emplace_back(pair); }

        std::sort(pairs.begin(), pairs.end());

        return pairs;
    }

    std::vector<std::pair<Bytes, Bytes>> DB::rangeNext(const Bytes& begin, int limit) {
        std::unordered_map<Bytes, Bytes> findPairs;
        std::unordered_set<Bytes> deletedKeys;

        _mutable->rangeNext(begin, limit, findPairs, deletedKeys);
        _immutable->rangeNext(begin, limit, findPairs, deletedKeys);
        _levelTree->rangeNext(begin, limit, findPairs, deletedKeys);

        std::vector<std::pair<Bytes, Bytes>> pairs;
        for (auto pair: findPairs) { pairs.emplace_back(pair); }

        std::sort(pairs.begin(), pairs.end());

        return pairs;
    }
}// namespace LynxDB