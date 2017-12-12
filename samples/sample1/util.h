/*
    Copyright 2017 Dynatrace LLC

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef SAMPLE1_UTIL_H_INCLUDED
#define SAMPLE1_UTIL_H_INCLUDED

#include <string>

/*========================================================================================================================================*/

std::string sql_escape(std::string const& str) {
    std::string result;
    result.reserve(str.size());
    for (std::string::size_type i = 0; i < str.size(); i++) {
        char const c = str[i];
        result += c;
        if (c == '\'')
            result += c;
    }
    return result;
}

/*========================================================================================================================================*/

#endif
