//     __ _____ _____ _____
//  __|  |   __|     |   | |  JSON for Modern C++
// |  |  |__   |  |  | | | |  version 3.11.3
// |_____|_____|_____|_|___|  https://github.com/nlohmann/json
//
// SPDX-FileCopyrightText: 2013-2023 Niels Lohmann <https://nlohmann.me>
// SPDX-License-Identifier: MIT

#pragma once

#include <type_traits> // conditional, is_same
#include <string>

#include <nlohmann/detail/abi_macros.hpp>

NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{

/*!
@brief Custom base class of the @ref basic_json class.

*/
class json_base_class_with_start_end_markers
{
    size_t start_position = std::string::npos;
    size_t end_position = std::string::npos;

  public:
    size_t get_start_position() const noexcept
    {
        return start_position;
    }

    size_t get_end_position() const noexcept
    {
        return end_position;
    }

    void set_start_position(size_t start) noexcept
    {
        start_position = start;
    }

    void set_end_position(size_t end) noexcept
    {
        end_position = end;
    }
};

}  // namespace detail
NLOHMANN_JSON_NAMESPACE_END
