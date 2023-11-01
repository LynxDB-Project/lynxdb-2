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

#include "LevelTree.h"

namespace LynxDB {
    LevelTree::LevelTree(const std::filesystem::path& dbPath) {
        std::filesystem::directory_iterator dirItr(dbPath);

        for (auto& dir: dirItr) {
            if (dir.is_directory()) {
                std::string subDirName = dir.path().filename().string();
                try {
                    int levelNo = std::stoi(subDirName);
                    _levels.push_back(new Level(levelNo));
                } catch (std::invalid_argument& e) {
                    // handle exception ...
                } catch (std::out_of_range& e) {
                    // handle exception ...
                }
            }
        }
    }

    LevelTree::~LevelTree() {
        for (auto level: _levels) { delete level; }
    }

    void LevelTree::merge(MemTable* memTable) {}

    Bytes LevelTree::find(const Bytes& key) { return Bytes(""); }

    void LevelTree::rangeBefore(const Bytes& begin, int limit,
                                std::unordered_map<Bytes, Bytes>& findPairs,
                                std::unordered_set<Bytes>& deletedKeys) {}
    
    void LevelTree::rangeNext(const Bytes& begin, int limit,
                              std::unordered_map<Bytes, Bytes>& findPairs,
                              std::unordered_set<Bytes>& deletedKeys) {}
}// namespace LynxDB