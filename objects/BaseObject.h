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
    BaseObject(SimpleType type) : type(type) {}


    SimpleType GetType() const {
        return type;
    }

private:
    SimpleType type;
};