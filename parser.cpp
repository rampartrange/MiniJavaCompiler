// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 42 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"

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

    #include "expressions/AssignmentExpression.h"
    #include "assignments/AssignmentList.h"
    #include "assignments/DeclarationList.h"
    #include "assignments/IdentList.h"

    #include "Program.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 79 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 171 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"

  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_assignment: // assignment
        value.YY_MOVE_OR_COPY< AssignmentExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_MainBlock: // MainBlock
      case symbol_kind::S_assignments: // assignments
        value.YY_MOVE_OR_COPY< AssignmentList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DeclBlock: // DeclBlock
      case symbol_kind::S_declarations: // declarations
        value.YY_MOVE_OR_COPY< DeclarationList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IdentList: // IdentList
      case symbol_kind::S_IdentListSeq: // IdentListSeq
        value.YY_MOVE_OR_COPY< IdentList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
        value.YY_MOVE_OR_COPY< Program* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_REAL: // "real"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE: // "type"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_CMP: // CMP
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_assignment: // assignment
        value.move< AssignmentExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_MainBlock: // MainBlock
      case symbol_kind::S_assignments: // assignments
        value.move< AssignmentList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DeclBlock: // DeclBlock
      case symbol_kind::S_declarations: // declarations
        value.move< DeclarationList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IdentList: // IdentList
      case symbol_kind::S_IdentListSeq: // IdentListSeq
        value.move< IdentList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unit: // unit
        value.move< Program* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_REAL: // "real"
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE: // "type"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_CMP: // CMP
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_assignment: // assignment
        value.copy< AssignmentExpression* > (that.value);
        break;

      case symbol_kind::S_MainBlock: // MainBlock
      case symbol_kind::S_assignments: // assignments
        value.copy< AssignmentList* > (that.value);
        break;

      case symbol_kind::S_DeclBlock: // DeclBlock
      case symbol_kind::S_declarations: // declarations
        value.copy< DeclarationList* > (that.value);
        break;

      case symbol_kind::S_exp: // exp
        value.copy< Expression* > (that.value);
        break;

      case symbol_kind::S_IdentList: // IdentList
      case symbol_kind::S_IdentListSeq: // IdentListSeq
        value.copy< IdentList* > (that.value);
        break;

      case symbol_kind::S_unit: // unit
        value.copy< Program* > (that.value);
        break;

      case symbol_kind::S_BOOL: // "bool"
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_REAL: // "real"
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE: // "type"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_CMP: // CMP
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_assignment: // assignment
        value.move< AssignmentExpression* > (that.value);
        break;

      case symbol_kind::S_MainBlock: // MainBlock
      case symbol_kind::S_assignments: // assignments
        value.move< AssignmentList* > (that.value);
        break;

      case symbol_kind::S_DeclBlock: // DeclBlock
      case symbol_kind::S_declarations: // declarations
        value.move< DeclarationList* > (that.value);
        break;

      case symbol_kind::S_exp: // exp
        value.move< Expression* > (that.value);
        break;

      case symbol_kind::S_IdentList: // IdentList
      case symbol_kind::S_IdentListSeq: // IdentListSeq
        value.move< IdentList* > (that.value);
        break;

      case symbol_kind::S_unit: // unit
        value.move< Program* > (that.value);
        break;

      case symbol_kind::S_BOOL: // "bool"
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_REAL: // "real"
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE: // "type"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_CMP: // CMP
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_assignment: // assignment
        yylhs.value.emplace< AssignmentExpression* > ();
        break;

      case symbol_kind::S_MainBlock: // MainBlock
      case symbol_kind::S_assignments: // assignments
        yylhs.value.emplace< AssignmentList* > ();
        break;

      case symbol_kind::S_DeclBlock: // DeclBlock
      case symbol_kind::S_declarations: // declarations
        yylhs.value.emplace< DeclarationList* > ();
        break;

      case symbol_kind::S_exp: // exp
        yylhs.value.emplace< Expression* > ();
        break;

      case symbol_kind::S_IdentList: // IdentList
      case symbol_kind::S_IdentListSeq: // IdentListSeq
        yylhs.value.emplace< IdentList* > ();
        break;

      case symbol_kind::S_unit: // unit
        yylhs.value.emplace< Program* > ();
        break;

      case symbol_kind::S_BOOL: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_REAL: // "real"
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTEGER: // "integer"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_TYPE: // "type"
      case symbol_kind::S_STRING: // "string"
      case symbol_kind::S_CMP: // CMP
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // unit: DeclBlock MainBlock "end of file"
#line 150 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                                {yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < AssignmentList* > (), NULL, yystack_[2].value.as < DeclarationList* > ()); driver.program = yylhs.value.as < Program* > (); }
#line 796 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 3: // DeclBlock: %empty
#line 153 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
           { yylhs.value.as < DeclarationList* > () = NULL; }
#line 802 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 4: // DeclBlock: "var" declarations
#line 154 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                         { yylhs.value.as < DeclarationList* > () = yystack_[0].value.as < DeclarationList* > (); }
#line 808 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 5: // declarations: %empty
#line 157 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
           { yylhs.value.as < DeclarationList* > ()  = new DeclarationList(); }
#line 814 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 6: // declarations: declarations IdentList ":" "type" ";"
#line 158 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                                            {
        yystack_[3].value.as < IdentList* > ()->SetType(yystack_[1].value.as < std::string > ());
        for (const auto& name : yystack_[3].value.as < IdentList* > ()->GetIdentList()) {
            std::cout << name << ": " << yystack_[3].value.as < IdentList* > ()->GetType() << std::endl;
        }
        yystack_[4].value.as < DeclarationList* > ()->AddDeclaration(yystack_[3].value.as < IdentList* > ());
        yylhs.value.as < DeclarationList* > () = yystack_[4].value.as < DeclarationList* > ();
    }
#line 827 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 8: // IdentList: "identifier" IdentListSeq
#line 168 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                                {
        yystack_[0].value.as < IdentList* > ()->AddIdent(yystack_[1].value.as < std::string > ());
        yylhs.value.as < IdentList* > () = yystack_[0].value.as < IdentList* > ();
    }
#line 836 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 9: // IdentListSeq: %empty
#line 174 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
           { yylhs.value.as < IdentList* > () = new IdentList(); }
#line 842 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 10: // IdentListSeq: IdentListSeq "," "identifier"
#line 175 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                                    {
        yystack_[2].value.as < IdentList* > ()->AddIdent(yystack_[0].value.as < std::string > ());
        yylhs.value.as < IdentList* > () = yystack_[2].value.as < IdentList* > ();
    }
#line 851 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 11: // MainBlock: "begin" assignments "end" "."
#line 181 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                                          { yylhs.value.as < AssignmentList* > () = yystack_[2].value.as < AssignmentList* > (); }
#line 857 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 12: // assignments: %empty
#line 184 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
           { yylhs.value.as < AssignmentList* > () = new AssignmentList(); /* A -> eps */}
#line 863 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 13: // assignments: assignments assignment
#line 185 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                             {
        yystack_[1].value.as < AssignmentList* > ()->AddAssignment(yystack_[0].value.as < AssignmentExpression* > ()); yylhs.value.as < AssignmentList* > () = yystack_[1].value.as < AssignmentList* > ();
    }
#line 871 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 14: // assignment: "identifier" ":=" exp ";"
#line 191 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                             {
        yylhs.value.as < AssignmentExpression* > () = new AssignmentExpression(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expression* > ());
        driver.variables[yystack_[3].value.as < std::string > ()] = yystack_[1].value.as < Expression* > ()->eval(); 
    }
#line 880 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 15: // exp: exp CMP exp
#line 198 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                { yylhs.value.as < Expression* > () = new ComparisonExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > (), yystack_[1].value.as < std::string > ()); }
#line 886 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 16: // exp: "integer"
#line 199 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                { yylhs.value.as < Expression* > () = new ObjectExpression(yystack_[0].value.as < int > ()); }
#line 892 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 17: // exp: "real"
#line 200 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                { yylhs.value.as < Expression* > () = new ObjectExpression(yystack_[0].value.as < double > ()); }
#line 898 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 18: // exp: "string"
#line 201 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                { yylhs.value.as < Expression* > () = new ObjectExpression(yystack_[0].value.as < std::string > ()); }
#line 904 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 19: // exp: "bool"
#line 202 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                { yylhs.value.as < Expression* > () = new ObjectExpression(yystack_[0].value.as < bool > ()); }
#line 910 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 20: // exp: "identifier"
#line 203 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                   {yylhs.value.as < Expression* > () = new IdentExpression(yystack_[0].value.as < std::string > (), driver.variables[yystack_[0].value.as < std::string > ()]); }
#line 916 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 21: // exp: exp "+" exp
#line 204 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                  { yylhs.value.as < Expression* > () = new AddExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 922 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 22: // exp: exp "-" exp
#line 205 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                  { yylhs.value.as < Expression* > () = new SubstractExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 928 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 23: // exp: exp "*" exp
#line 206 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                  { yylhs.value.as < Expression* > () = new MulExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 934 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 24: // exp: exp "/" exp
#line 207 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                  { yylhs.value.as < Expression* > () = new DivExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 940 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 25: // exp: exp "%" exp
#line 208 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                  { yylhs.value.as < Expression* > () = new ModExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 946 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 26: // exp: exp "&&" exp
#line 209 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                   { yylhs.value.as < Expression* > () = new AndExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 952 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 27: // exp: exp "||" exp
#line 210 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                   { yylhs.value.as < Expression* > () = new OrExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 958 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 28: // exp: exp "^" exp
#line 211 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                    { yylhs.value.as < Expression* > () = new XorExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 964 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 29: // exp: "!" exp
#line 212 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                    { yylhs.value.as < Expression* > () = new NotExpression(yystack_[0].value.as < Expression* > ()); }
#line 970 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 30: // exp: "(" exp ")"
#line 213 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                  { yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); }
#line 976 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 31: // exp: "-" exp
#line 214 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"
                           { yylhs.value.as < Expression* > () = new UnaryMinusExpression(yystack_[0].value.as < Expression* > ()); }
#line 982 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;


#line 986 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -15;

  const signed char parser::yytable_ninf_ = -8;

  const signed char
  parser::yypact_[] =
  {
       5,   -15,    12,    18,   -14,   -15,   -15,    32,   -15,    11,
      35,   -15,    14,    20,    26,    41,   -15,    36,    42,   -15,
      49,   -15,   -15,    49,    49,    49,   -15,   -15,   -15,   -15,
     -15,    -7,   -15,   -15,     6,    49,    49,    49,    49,    49,
      49,    49,    49,   -15,    49,   -15,    31,    31,   -15,   -15,
     -15,   -15,    31,    31,    17
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     5,     0,     0,     4,     1,    12,     0,     9,     0,
       0,     2,     8,     0,     0,     0,    13,     0,     0,    11,
       0,    10,     6,     0,     0,     0,    20,    16,    17,    18,
      19,     0,    31,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,    30,    22,    21,    23,    24,
      25,    26,    27,    28,    15
  };

  const signed char
  parser::yypgoto_[] =
  {
     -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,    13
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     9,    12,     7,    10,    16,    31
  };

  const signed char
  parser::yytable_[] =
  {
      35,    36,    37,    38,    39,    40,    41,    42,    -7,     8,
       1,    43,     5,    35,    36,    37,    38,    39,    40,    41,
      42,     6,    44,    45,    35,    36,    37,    38,    39,    40,
      41,    42,    11,    13,    17,    44,    32,    33,    34,    14,
      37,    38,    39,    40,    18,    19,    -8,    20,    46,    47,
      48,    49,    50,    51,    52,    53,    23,    54,    15,    21,
      22,     0,     0,     0,    24,    25,     0,     0,     0,     0,
       0,     0,    26,     0,    27,    28,    29,    30
  };

  const signed char
  parser::yycheck_[] =
  {
       7,     8,     9,    10,    11,    12,    13,    14,    22,    23,
       5,    18,     0,     7,     8,     9,    10,    11,    12,    13,
      14,     3,    29,    17,     7,     8,     9,    10,    11,    12,
      13,    14,     0,    22,    20,    29,    23,    24,    25,     4,
       9,    10,    11,    12,    24,    19,    29,     6,    35,    36,
      37,    38,    39,    40,    41,    42,     7,    44,    23,    23,
      18,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    27,    28
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    32,    33,    34,     0,     3,    37,    23,    35,
      38,     0,    36,    22,     4,    23,    39,    20,    24,    19,
       6,    23,    18,     7,    15,    16,    23,    25,    26,    27,
      28,    40,    40,    40,    40,     7,     8,     9,    10,    11,
      12,    13,    14,    18,    29,    17,    40,    40,    40,    40,
      40,    40,    40,    40,    40
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    31,    32,    33,    33,    34,    34,    35,    35,    36,
      36,    37,    38,    38,    39,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     0,     2,     0,     5,     0,     2,     0,
       3,     4,     0,     2,     4,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"begin\"", "\"end\"",
  "\"var\"", "\":=\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"",
  "\"&&\"", "\"||\"", "\"^\"", "\"!\"", "\"(\"", "\")\"", "\";\"", "\".\"",
  "\",\"", "i", "\":\"", "\"identifier\"", "\"type\"", "\"integer\"",
  "\"real\"", "\"string\"", "\"bool\"", "CMP", "UMINUS", "$accept", "unit",
  "DeclBlock", "declarations", "IdentList", "IdentListSeq", "MainBlock",
  "assignments", "assignment", "exp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   150,   150,   153,   154,   157,   158,   167,   168,   174,
     175,   181,   184,   185,   191,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1485 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.cpp"

#line 216 "/Users/rampartrange/CompilersCourse/03-parsers-with-ast/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
