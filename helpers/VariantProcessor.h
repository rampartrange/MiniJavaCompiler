#pragma once
#include <iostream>
#include <variant>
#include "parser.hh"

using location_type = yy::parser::location_type;
using BasicTypes = std::variant<int, bool, std::string>;

class VariantProcessor {
public:
    static void ExitWithError(const std::string &message, const location_type& loc) {
        std::cout << "Error: " << message << " at : " << loc << std::endl;
        exit(0);
    }

    template <typename T>
    static T GetValue(BasicTypes object, const location_type& loc) {
        if (auto* val = std::get_if<T>(&object)) {
            return *val;
        }
        ExitWithError("Non matching types", loc);
    }

    static void PrintValue(BasicTypes object) {
        if (auto* val = std::get_if<int>(&object)) {
            std::cout << *val << std::endl;
        } else if (auto* val = std::get_if<bool>(&object)) {
            std::cout <<std::boolalpha <<*val << std::endl;
        } else if (auto* val = std::get_if<std::string>(&object)) {
            std::cout << *val << std::endl;
        }
    }
};


