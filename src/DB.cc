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
    DB::DB(std::filesystem::path& dbPath) {

    }

    DB::~DB() {

    }

    void DB::insert(Bytes &key, Bytes &value) {

    }

    Bytes &DB::find(Bytes &key) {
        auto *value = new LynxDB::Bytes("value");
        return *value;
    }

    void DB::remove(Bytes &key) {

    }

    std::vector<std::pair<Bytes &, Bytes &>> &DB::rangeBefore(Bytes &begin, int limit) {
        auto pairs = new std::vector<std::pair<Bytes&, Bytes&>>;
        return *pairs;
    }

    std::vector<std::pair<Bytes &, Bytes &>> &DB::rangeNext(Bytes &begin, int limit) {
        auto pairs = new std::vector<std::pair<Bytes&, Bytes&>>;
        return *pairs;
    }
} // LynxDB