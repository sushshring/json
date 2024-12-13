#include <iostream>

# define JSON_DIAGNOSTIC_POSITIONS 1
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    std::string json_string = R"(
    {
        "address": {
            "street": "Fake Street",
            "housenumber": 1
        }
    }
    )";
    json j = json::parse(json_string);

    std::cout << "Root diagnostic positions: \n";
    std::cout << "\tstart_pos: " << j.start_pos() << '\n';
    std::cout << "\tend_pos:" << j.end_pos() << "\n\n";

    std::cout << "address diagnostic positions: \n";
    std::cout << "\tstart_pos:" << j["address"].start_pos() << '\n';
    std::cout << "\tend_pos:" << j["address"].end_pos() << "\n\n";

    std::cout << "street diagnostic positions: \n";
    std::cout << "\tstart_pos:" << j["address"]["street"].start_pos() << '\n';
    std::cout << "\tend_pos:" << j["address"]["street"].end_pos() << "\n\n";

    std::cout << "housenumber diagnostic positions: \n";
    std::cout << "\tstart_pos:" << j["address"]["housenumber"].start_pos() << '\n';
    std::cout << "\tend_pos:" << j["address"]["housenumber"].end_pos() << "\n\n";
}
