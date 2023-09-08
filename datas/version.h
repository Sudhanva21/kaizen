// MIT License
// 
// Copyright (c) 2023 Leo Heinsaar
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <ostream>
#include <regex>
#include <stdexcept>

namespace zen {

///////////////////////////////////////////////////////////////////////////////////////////// zen::version

struct version : std::array<int,4> {  // read 'struct' as "extend the interface"
    version(int major, int minor, int patch, int build)
        : std::array<int,4>{major, minor, patch, build}
    {}

    explicit version(const zen::string& text)
    {
        static const std::regex rx_version{R"((\d+)\.(\d+)\.(\d+)\.(\d+))"};
        if (std::smatch sm; std::regex_match(text, sm, rx_version)) {
            at(0) = std::stoi(sm[1]);
            at(1) = std::stoi(sm[2]);
            at(2) = std::stoi(sm[3]);
            at(3) = std::stoi(sm[4]);
        } else {
            throw std::invalid_argument{"The given text does not match the version string pattern."};
        }
    }

    constexpr auto major() const { return at(0); }
    constexpr auto minor() const { return at(1); }
    constexpr auto patch() const { return at(2); }
    constexpr auto build() const { return at(3); }
};

std::ostream& operator<<(std::ostream& os, const version& v)
{
    return os << v.major() << '.' << v.minor() << '.' << v.patch() << '.' << v.build();
}

namespace version_literals {

version operator""_version(const char* text, size_t)
{
    return version{text};
}

} // namespace version_literals

} // namespace zen