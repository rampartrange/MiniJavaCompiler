cmake_minimum_required(VERSION 3.15)
project(MiniJavaCompiler)

set (CMAKE_CXX_STANDARD 17)

set(
    HEADERS
    driver.hh
    parser.hh
    )

find_package(BISON REQUIRED)
BISON_TARGET(
    MyParser
    parser.y
    ${MiniJavaCompiler_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${MiniJavaCompiler_SOURCE_DIR}/parser.hh
)

find_package(FLEX REQUIRED)
FLEX_TARGET(
    MyScanner
    scanner.l
    ${MiniJavaCompiler_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
        MiniJavaCompiler

        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}

        expressions/objects/ObjectExpression.cpp
        expressions/objects/IdentExpression.cpp
        expressions/objects/AssignmentExpression.cpp

        expressions/arithmetic/MulExpression.cpp
        expressions/arithmetic/AddExpression.cpp
        expressions/arithmetic/SubstractExpression.cpp
        expressions/arithmetic/UnaryMinusExpression.cpp
        expressions/arithmetic/DivExpression.cpp
        expressions/arithmetic/ModExpression.cpp

        expressions/logic/ComparisonExpression.cpp
        expressions/logic/AndExpression.cpp
        expressions/logic/OrExpression.cpp
        expressions/logic/XorExpression.cpp
        expressions/logic/NotExpression.cpp

        assignments/AssignmentList.cpp
        assignments/Assignment.cpp

        statements/statement.cpp

        objects/PascalObject.cpp
        objects/IntegerObject.cpp
        objects/BooleanObject.cpp
        objects/StringObject.cpp

        visitors/printvisitor.cpp
        visitors/interpreter.cpp

        Program.cpp)


target_include_directories(
        MiniJavaCompiler PRIVATE ${MiniJavaCompiler_SOURCE_DIR}
)



