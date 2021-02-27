cmake_minimum_required(VERSION 3.15)
project(MiniJavaCompiler)

set (CMAKE_CXX_STANDARD 11)

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

        expressions/ObjectExpression.cpp
        expressions/MulExpression.cpp
        expressions/AddExpression.cpp
        expressions/SubstractExpression.cpp
        expressions/UnaryMinusExpression.cpp
        expressions/DivExpression.cpp
        expressions/ModExpression.cpp
        expressions/IdentExpression.cpp
        expressions/ComparisonExpression.cpp
        expressions/AndExpression.cpp
        expressions/OrExpression.cpp
        expressions/XorExpression.cpp
        expressions/NotExpression.cpp
        expressions/AssignmentExpression.cpp

        assignments/AssignmentList.cpp
        assignments/Assignment.cpp

        objects/PascalObject.cpp
        objects/IntegerObject.cpp
        objects/BooleanObject.cpp
        objects/DoubleObject.cpp
        objects/StringObject.cpp

        visitors/evalvisitor.cpp
        visitors/printvisitor.cpp


        Program.cpp
)


target_include_directories(
        MiniJavaCompiler PRIVATE ${MiniJavaCompiler_SOURCE_DIR}
)



