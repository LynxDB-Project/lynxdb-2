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

#ifndef LYNXDB_BYTES_H
#define LYNXDB_BYTES_H

#include <string>

namespace LynxDB {

    class Bytes {
    private:
        const char* _data;
        size_t _size;
    public:
        Bytes() = delete;
        explicit Bytes(const std::string& s) : _size(s.size()), _data(s.data()) {};

        bool operator==(const Bytes& b) const;
        bool operator>(const Bytes& b) const;
        bool operator<(const Bytes& b) const;
    };

} // LynxDB

#endif //LYNXDB_BYTES_H
