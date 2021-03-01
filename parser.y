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
    class BaseObject;
    class BooleanObject;
    class DoubleObject;
    class IntegerObject;
    class StringObject;

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

    #include "expressions/objects/ObjectExpression.h"
    #include "expressions/objects/IdentExpression.h"

    #include "expressions/arithmetic/AddExpression.h"
    #include "expressions/arithmetic/MulExpression.h"
    #include "expressions/arithmetic/DivExpression.h"
    #include "expressions/arithmetic/SubstractExpression.h"
    #include "expressions/arithmetic/ModExpression.h"
    #include "expressions/arithmetic/UnaryMinusExpression.h"

    #include "expressions/logic/ComparisonExpression.h"
    #include "expressions/logic/AndExpression.h"
    #include "expressions/logic/OrExpression.h"
    #include "expressions/logic/XorExpression.h"
    #include "expressions/logic/NotExpression.h"

    #include "objects/PascalObject.h"
    #include "objects/BaseObject.h"
    #include "objects/IntegerObject.h"
    #include "objects/DoubleObject.h"
    #include "objects/BooleanObject.h"
    #include "objects/StringObject.h"

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

    ASSIGN      "="

    CLASS 	"class"
    PUBLIC	"public"
    STATIC	"static"
    VOID	"void"
    MAIN	"main"


    MINUS       "-"
    PLUS        "+"
    STAR        "*"
    DIV         "/"
    MOD         "%"

    AND         "&&"
    OR          "||"
    XOR         "^"
    NOT         "!"

    LROUND      "("
    RROUND      ")"
    LCURLY	"{"
    RCURLY	"}"
    LSQUARE	"["
    RSQUARE	"]"

    SEMICOLON   ";"
    POINT       "."
    COMMA       ","
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


//For debug purpuses
%nterm <AssignmentList*> main_class

%nterm <Expression*> exp
%nterm <Assignment*> assignment
%nterm <AssignmentList*> assignments
%nterm <Program*> program

// %printer { yyo << $$; } <*>;

%nonassoc CMP
%right "="
%left "+" "-" "||" "^"
%left "*" "/" "%" "&&"
%nonassoc UMINUS
%nonassoc "!"

%%
%start program;

program: main_class {$$ = new Program($1, NULL);  driver.program = $$; };

main_class: "class" "identifier" "{"
		"public" "static" "void" "main" "(" ")"  "{"
		assignments "}" "}" {$$ = $11;};


assignments:
    %empty { $$ = new AssignmentList(); /* A -> eps */}
    | assignments assignment {
        $1->AddAssignment($2, @$); $$ = $1;
    };

assignment:
    "identifier" "=" exp ";" {
        $$ = new Assignment($1, $3, @$);
        driver.variables[$1] = $3->eval();
    };



exp:
    "integer" {$$ = new ObjectExpression($1, @$); }
    | "identifier" {$$ = new IdentExpression($1, driver.variables[$1], @$); }
    //exp binary_operator exp {}
    | exp "+" exp { $$ = new AddExpression($1, $3, @$); }
    | exp "-" exp { $$ = new SubstractExpression($1, $3, @$); }
    | exp "*" exp { $$ = new MulExpression($1, $3, @$); }
    | exp "/" exp { $$ = new DivExpression($1, $3, @$); }
    | "(" exp ")" { $$ = $2; };

binary_operator:
    "&&"
    | "||"
    | "^"
    | "<"
    | ">"
    | ">="
    | "<="
    | "=="
    | "!="
    | "+"
    | "-"
    | "*"
    | "/"
    | "%";

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
