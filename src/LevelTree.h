//
// Created by Baili Zhang on 2023/10/23.
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

#ifndef LYNXDB_LEVELTREE_H
#define LYNXDB_LEVELTREE_H

#include <filesystem>
#include <list>

#include "Bytes.h"
#include "Level.h"
#include "MemTable.h"

namespace LynxDB {

    class LevelTree {
    private:
        std::list<Level*> _levels;

    public:
        LevelTree() = delete;
        explicit LevelTree(const std::filesystem::path& dbPath);
        ~LevelTree();

        void merge(MemTable* memTable);
        Bytes find(const Bytes& key);
    };

}// namespace LynxDB

#endif//LYNXDB_LEVELTREE_H
