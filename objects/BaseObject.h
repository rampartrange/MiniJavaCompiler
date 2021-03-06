#pragma once

enum class SimpleType {
    INT,
    BOOLEAN,
    STRING,
    DOUBLE,
    VOID
};

class BaseObject {
public:
    virtual void Accept() = 0;

    virtual SimpleType GetType() const = 0;

    virtual ~BaseObject() = default;
};
