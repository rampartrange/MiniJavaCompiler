# Компилятор MiniJava (Андрианов Артем, Платинский Степан Б05-924)

### Status:

| Checkpoints                                                                                                                          | Status         | 
| -------------                                                                                                                        |:-------------: |
| [AST + locations](https://github.com/akhtyamovpavel/CompilersCourse/blob/master/milestones/milestones-2021/01-ast-locations.md)      | DONE		| 
| [Visitors + Semantics](https://github.com/akhtyamovpavel/CompilersCourse/blob/master/milestones/milestones-2021/02-visitors-table.md)	| Pending Review |
| [Symbol table + Type system](https://github.com/akhtyamovpavel/CompilersCourse/blob/master/milestones/milestones-2021/03-pair-symbol-table-types.md) | In process|

### Done:
1. [**Lexical analyser**](scanner.l)
2. [**Parser**](parser.y) with a little snippet of [**MiniJava grammar**](https://github.com/akhtyamovpavel/CompilersCourse/blob/master/reqs-draft.md)
3. [**PrintVisior**](visitors/printvisitor.h) which builds relevant AST + tracks each AST node location in source code
4. [**Interpeter**](visitors/interpreter.h) which interpets code
5. Made support of Int, Boolean and String objects
6. Made error trasing(e.g. unsupported types/conversions)

### In Proccess:
1. Creating statement class 
2. Adding more grammar
3. Adding more base symbols
4. Building symbol table

### How To Launch:
```
mkdir build
cd build
cmake .. && make
./MiniJavaCompiler <path/to/file>
```

**REMARK!**

Now supports alike snippets of code:
```Java
class Factorial {
  public static void main () {
    vitalik = 3 + 5;
    b = -vitalik;
    c = "asd";
    d = "abc";
    b = c < d;
  }
}

```
Which outputs stored variables and their values

### Launch code with the [_test_](test.txt) _snippet_:
```
./MiniJavaCompiler ../test.txt
```
The code must return:
```
../test.txt
Compile OK
PrintVisitor OK
Interpreter OK

Variables values: 
b false
c asd
d abc
vitalik 8
```

### PrintVisitor:
The output of PrintVisitor you can find in _build_ directory

PrintVisitor's result for the [_test_](test.txt) _snippet_:
```
Program (loc): 
	AssignmentList (loc): ../test.txt:2.31 
		Assignment:  (loc): ../test.txt:3.5-20 (var name): vitalik
			AddExpression (loc): ../test.txt:3.15-19 
				IntegerExpression (loc): ../test.txt:3.15 
					3
				IntegerExpression (loc): ../test.txt:3.19 
					5
		Assignment:  (loc): ../test.txt:4.5-17 (var name): b
			UnaryMinusExpression (loc): ../test.txt:4.9-16 
				IdentExpression (loc): ../test.txt:4.10-16 vitalik
					AddExpression (loc): ../test.txt:3.15-19 
						IntegerExpression (loc): ../test.txt:3.15 
							3
						IntegerExpression (loc): ../test.txt:3.19 
							5
		Assignment:  (loc): ../test.txt:5.5-14 (var name): c
			StringExpression (loc): ../test.txt:5.9-13 
				asd
		Assignment:  (loc): ../test.txt:6.5-14 (var name): d
			StringExpression (loc): ../test.txt:6.9-13 
				abc
		Assignment:  (loc): ../test.txt:7.5-14 (var name): b
			ComparisonExpression (loc): ../test.txt:7.9-13 
				IdentExpression (loc): ../test.txt:7.9 c
					StringExpression (loc): ../test.txt:5.9-13 
						asd
				type : <
				IdentExpression (loc): ../test.txt:7.13 d
					StringExpression (loc): ../test.txt:6.9-13 
						abc

```
