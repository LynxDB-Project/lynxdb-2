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

#include "DB.h"

namespace LynxDB {
    DB::DB(const std::filesystem::path& dbPath)
        : _mutable(new MemTable)
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
            _mutable = new MemTable();
            _levelTree->merge(needMerge);
        }

        _mutable->insert(key, value);
    }

    Bytes DB::find(const Bytes& key) {
        try {
            LynxDB::Bytes value = _mutable->find(key);
            if (!value.empty()) { return value; }

            value = _immutable->find(key);
            if (!value.empty()) { return value; }

            return _levelTree->find(key);
        } catch (DeletedException& e) {
            // handle key deleted...
        }
    }

    void DB::remove(const Bytes& key) {
        if (_mutable->full()) {
            MemTable* needMerge = _immutable;
            _immutable = _mutable;
            _mutable = new MemTable();
            _levelTree->merge(needMerge);
        }

        _mutable->remove(key);
    }

    std::vector<std::pair<Bytes&, Bytes&>> DB::rangeBefore(const Bytes& begin, int limit) {
        std::vector<std::pair<Bytes&, Bytes&>> pairs = _mutable->rangeBefore(begin, limit);
        // TODO
        return pairs;
    }

    std::vector<std::pair<Bytes&, Bytes&>> DB::rangeNext(const Bytes& begin, int limit) {
        std::vector<std::pair<Bytes&, Bytes&>> pairs = _mutable->rangeNext(begin, limit);
        // TODO
        return pairs;
    }
}// namespace LynxDB