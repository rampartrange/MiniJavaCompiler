cmake_minimum_required(VERSION 3.15)
project(MiniJavaCompiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    HEADERS
    driver.hh
    parser.hh
    )

find_package(BISON 3.5 REQUIRED)
BISON_TARGET(
    MyParser
    parser.y
    ${MiniJavaCompiler_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${MiniJavaCompiler_SOURCE_DIR}/parser.hh
)

find_package(FLEX 2.6.4 REQUIRED)
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

        objects/PascalObject.cpp
        objects/IntegerObject.cpp
        objects/BooleanObject.cpp
        objects/StringObject.cpp

        visitors/printvisitor.cpp
        visitors/interpreter.cpp
        visitors/symboltreevisitor.cpp

        statements/Assignment.cpp
        statements/AssignmentList.cpp
        statements/Declaration.cpp
        statements/DeclarationList.cpp
        statements/IfStatement.cpp
        statements/WhileStatement.cpp
        statements/StatementList.cpp
        
        symbol_table/Symbol.cpp
        symbol_table/Table.cpp
        symbol_table/ScopeLayer.cpp
        symbol_table/ScopeLayerTree.cpp

        Program.cpp )


target_include_directories(
        MiniJavaCompiler PRIVATE ${MiniJavaCompiler_SOURCE_DIR}
)
target_include_directories(MiniJavaCompiler PUBLIC ${FLEX_INCLUDE_DIRS})
