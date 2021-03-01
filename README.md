# Компилятор MiniJava (Андрианов Артем, Платинский Степан Б05-924)

### Status:

| Checkpoints                                                                                                                          | Status         | 
| -------------                                                                                                                        |:-------------: |
| [AST + locations](https://github.com/akhtyamovpavel/CompilersCourse/blob/master/milestones/milestones-2021/01-ast-locations.md)      | Pending Review | 
| [Visitors + Semantics](https://github.com/akhtyamovpavel/CompilersCourse/blob/master/milestones/milestones-2021/02-visitors-table.md)| In Proccess    |

### Done:
1. [**Lexical analyser**](scanner.l)
2. [**Parser**](parser.y) with a little snippet of [**MiniJava grammar**](https://github.com/akhtyamovpavel/CompilersCourse/blob/master/reqs-draft.md)
3. [**PrintVisior**](visitors/printvisitor.h) which builds relevant AST + tracks each location in source code

### In Proccess:
1. Adding semantics to JavaObjects and getting rid of temporary PascalObject made for debug purposes 
2. Creating statement class 
3. Integrating new objects to driver
4. Creating InterpretVisitor and EvalVisitor

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
    b = 5 + vitalik;
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
../test.txt   // file directory
b 13          // value stored in b
vitalik 8     // value stored in vitalik
Compile OK
PrintVisitor OK
```

### PrintVisitor:
The output of PrintVisitor you can find in _build_ directory

PrintVisitor's result for the [_test_](test.txt) _snippet_:
```
Program (loc): 
	AssignmentList (loc): ../test.txt:2.31 
		Assignment:  (loc): ../test.txt:3.5-20 (var name): vitalik
			AddExpression (loc): ../test.txt:3.15-19 
				ObjectExpression (loc): ../test.txt:3.15 
					Pascal object (loc): 1.1 
						3
				ObjectExpression (loc): ../test.txt:3.19 
					Pascal object (loc): 1.1 
						5
		Assignment:  (loc): ../test.txt:4.5-20 (var name): b
			AddExpression (loc): ../test.txt:4.9-19 
				ObjectExpression (loc): ../test.txt:4.9 
					Pascal object (loc): 1.1 
						5
				IdentExpression (loc): ../test.txt:4.13-19 vitalik

```
