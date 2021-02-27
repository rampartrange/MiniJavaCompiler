%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;

    class Expression;
    class ObjectExpression;
    class AddExpression;
    class SubstractExpression;
    class DivExpression;
    class IdentExpression;
    class UnaryMinusExpression;

    class ComparisonExpression;
    class AndExpression;
    class OrExpression;
    class XorExpression;
    class NotExpression;

    class PascalObject;

    class Assignment;
    class AssignmentList;

    class Program;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "expressions/ObjectExpression.h"
    #include "expressions/AddExpression.h"
    #include "expressions/MulExpression.h"
    #include "expressions/DivExpression.h"
    #include "expressions/SubstractExpression.h"
    #include "expressions/IdentExpression.h"
    #include "expressions/ModExpression.h"
    #include "expressions/UnaryMinusExpression.h"

    #include "expressions/ComparisonExpression.h"
    #include "expressions/AndExpression.h"
    #include "expressions/OrExpression.h"
    #include "expressions/XorExpression.h"
    #include "expressions/NotExpression.h"

    #include "objects/PascalObject.h"

    #include "assignments/Assignment.h"
    #include "assignments/AssignmentList.h"
    #include "Program.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    EOF 0       "end of file"

    BEGIN       "begin"
    END         "end"

    VAR         "var"

    ASSIGN      ":="

    MINUS       "-"
    PLUS        "+"
    STAR        "*"
    DIV         "/"
    MOD         "%"

    AND         "&&"
    OR          "||"
    XOR         "^"
    NOT         "!"

    LPAREN      "("
    RPAREN      ")"

    SEMICOLON   ";"
    POINT       "."
    COMMA       ","i
    COLON       ":"
;

%token <std::string>
    IDENTIFIER "identifier"
    TYPE       "type"

%token <int> INTEGER "integer"
%token <double> REAL "real"
%token <std::string> STRING "string"
%token <bool> BOOL "bool"
%token <std::string> CMP


%nterm <Expression*> exp
%nterm <Assignment*> assignment
%nterm <AssignmentList*> assignments
%nterm <Program*> unit

// %printer { yyo << $$; } <*>;

%%
%start unit;

unit: assignments exp { $$ = new Program($1, $2); driver.program = $$; };

assignments:
    %empty { $$ = new AssignmentList(); /* A -> eps */}
    | assignments assignment {
        $1->AddAssignment($2); $$ = $1;
    };

assignment:
    "identifier" ":=" exp {
        $$ = new Assignment($1, $3);
        driver.variables[$1] = $3->eval();
    };

%left "+" "-";
%left "*" "/";

exp:
    "integer" {$$ = new ObjectExpression($1); }
    | "identifier" {$$ = new IdentExpression($1, driver.variables[$1]); }
    | exp "+" exp { $$ = new AddExpression($1, $3); }
    | exp "-" exp { $$ = new SubstractExpression($1, $3); }
    | exp "*" exp { $$ = new MulExpression($1, $3); }
    | exp "/" exp { $$ = new DivExpression($1, $3); }
    | "(" exp ")" { $$ = $2; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
