#pragma once

enum class SimpleType {
    INT,
    BOOLEAN,
    VOID
};

class JavaObject {
public:
    //virtual void Accept() = 0;

    virtual SimpleType GetType() const = 0;

    virtual ~JavaObject() = default;
};
