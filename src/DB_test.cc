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

#include <filesystem>
#include <gtest/gtest.h>

#include "DB.h"
#include "Bytes.h"

TEST(DBTest, InitDB) {
    std::filesystem::path dbPath("./db_test");
    LynxDB::DB db(dbPath);
}

TEST(DB_TEST, Insert) {
    std::filesystem::path dbPath("./db_test");
    LynxDB::DB db(dbPath);

    LynxDB::Bytes key("key"), value("value");
    db.insert(key, value);
}

TEST(DB_TEST, Find) {
    std::filesystem::path dbPath("./db_test");
    LynxDB::DB db(dbPath);

    LynxDB::Bytes key("key"), value("value");
    auto findValue = db.find(key);
    ASSERT_EQ(findValue, value);
}

TEST(DB_TEST, Remove) {
    std::filesystem::path dbPath("./db_test");
    LynxDB::DB db(dbPath);

    LynxDB::Bytes key("key");
    db.remove(key);
}