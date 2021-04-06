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

    class Statement;
    class Assignment;
    class AssignmentList;
    class Declaration;
    class DeclarationList;
    class IfStatement;
    class WhileStatement;
    class StatementList;

    class Program;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

 	#include "visitors/elements.h"

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

	IF 		"if"
	ELSE 	"else"
	WHILE	"while"

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
    CMP

%token <int> INTEGER "integer"
%token <double> REAL "real"
%token <std::string> STRING "string"
%token <bool> BOOL "bool"



//For debug purpuses
%nterm <StatementList*> main_class

%nterm <Expression*> exp
%nterm <Statement*> statement;
%nterm <StatementList*> statement_list;
%nterm <Assignment*> assignment
%nterm <AssignmentList*> assignments
%nterm <Declaration*> declaration
%nterm <Declaration*> variable_declaration
%nterm <DeclarationList*> declaration_list
%nterm <Program*> program
%nterm <std::string> type

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

class_declaration:
	"class" "identifier" "{" declaration_list "}" {}

main_class: "class" "identifier" "{"
	"public" "static" "void" "main" "(" ")"  "{"
	statement_list[statements] "}" "}" { $$ = $statements; };

declaration_list:
	%empty { $$ = new DeclarationList(@$); }
	| declaration_list declaration {
		$1->AddDeclaration($2); $$ = $1;
	};

declaration:
	variable_declaration { $$ = $1 };

variable_declaration: type "identifier" ";" { $$ = new Declaration($2, $1, @$); };

type:
	TYPE {$$ = $1; }
	| "identifier" {$$ = $1;};

statement_list:
	%empty { $$ = new StatementList(@$); }
	| statement_list statement {
		$1->AddStatement($2); $$ = $1;
	};

statement:
	variable_declaration {$$ = $1;}
	| "if" "(" exp ")" statement { $$ = new IfStatement($3, $5, @$); }
	| "if" "(" exp ")" statement "else" statement { $$ = new IfStatement($3, $5, $7, @$); }
	| "while" "(" exp ")" statement { $$ = new WhileStatement($3, $5, @$); }
	| assignment {$$ = $1; };

assignments:
    %empty { $$ = new AssignmentList(@$); /* A -> eps */}
    | assignments assignment {
        $1->AddAssignment($2); $$ = $1;
    };

assignment:
    "identifier" "=" exp ";" {
        $$ = new Assignment($1, $3, @$);
        driver.variables[$1] = $3;
    };

exp:
    "integer" {$$ = new ObjectExpression($1, @$); }
    | "string" {$$ = new ObjectExpression($1, @$); }
    | "bool" {$$ = new ObjectExpression($1, @$); }
    | "identifier" {$$ = new IdentExpression($1, driver.variables[$1], @$); }
    | exp CMP exp { $$ = new ComparisonExpression($1, $3, $2, @$); }
    | exp "+" exp { $$ = new AddExpression($1, $3, @$); }
    | exp "-" exp { $$ = new SubstractExpression($1, $3, @$); }
    | exp "*" exp { $$ = new MulExpression($1, $3, @$); }
    | exp "/" exp { $$ = new DivExpression($1, $3, @$); }
    | exp "&&" exp { $$ = new AndExpression($1, $3, @$); }
    | exp "||" exp { $$ = new OrExpression($1, $3, @$); }
    | exp "^" exp { $$ = new XorExpression($1, $3, @$); }
    | "!" exp     { $$ = new NotExpression($2, @$); }
    | "(" exp ")" { $$ = $2; };
    | "-" exp %prec UMINUS { $$ = new UnaryMinusExpression($2, @$); };


%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
