#pragma once
#include <iostream>
#include <variant>
using BasicTypes = std::variant<int, bool, std::string>;

class VariantProcessor {
public:
    static void ExitWithError(const std::string &message) {
        std::cout << "Error: " << message << std::endl;
        exit(0);
    }

    template <typename T>
    static T GetValue(BasicTypes object) {
        if (auto* val = std::get_if<T>(&object)) {
            return *val;
        }
        ExitWithError("Non matching types");
    }

    static void PrintValue(BasicTypes object) {
        if (auto* val = std::get_if<int>(&object)) {
            std::cout << *val << std::endl;
        } else if (auto* val = std::get_if<bool>(&object)) {
            std::cout << *val << std::endl;
        } else if (auto* val = std::get_if<std::string>(&object)) {
            std::cout << *val << std::endl;
        }
    }
};


