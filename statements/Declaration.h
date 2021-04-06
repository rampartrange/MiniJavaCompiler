#pragma once
#include <statements/Statement.h>
#include <string>

class Declaration : public Statement {
public:
    Declaration(std::string  variable,
    std::string type, const location_type &loc);

    void Accept(Visitor* visitor);

    std::string variable_;
    std::string type_;
};
