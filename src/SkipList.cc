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

#include "SkipList.h"

namespace LynxDB {
    SkipList::SkipList() {}
    SkipList::~SkipList() {}
    int SkipList::size() { return 0; }
    void SkipList::insert(const Bytes& key, const Bytes& value) {}
    void SkipList::remove(const Bytes& key) {}
    LynxDB::Bytes SkipList::find(const Bytes& key) { return Bytes(""); }
    void SkipList::rangeBefore(const Bytes& begin, int limit,
                               std::unordered_map<Bytes, Bytes>& findPairs,
                               std::unordered_set<Bytes>& deletedKeys) {}
    void SkipList::rangeNext(const Bytes& begin, int limit,
                             std::unordered_map<Bytes, Bytes>& findPairs,
                             std::unordered_set<Bytes>& deletedKeys) {}
}// namespace LynxDB