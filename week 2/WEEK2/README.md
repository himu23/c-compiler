A Parser that reads tokens from your lexer
A set of AST node classes that represent the program structure
A function to pretty print the AST
Basic error handling if the syntax is invalid


himu23@ideapad3:~/Desktop/projects/soc-now-u-c-me/week 2/WEEK2$ make clean
make
make run
rm -f parser
g++ -std=c++17 -Wall src/main.cpp src/lexer.cpp src/parser.cpp -o parser
src/lexer.cpp: In member function ‘std::vector<Token> Lexer::tokenize()’:
src/lexer.cpp:63:13: warning: unused variable ‘startCol’ [-Wunused-variable]
   63 |         int startCol = column;
      |             ^~~~~~~~
./parser tests/sample_programs/test2.c--
Token: DELIMITER (()
Token: NUMBER (2)
Token: OPERATOR (+)
Token: NUMBER (3)
Token: DELIMITER ())
Token: EOF (EOF)
AST:
BinaryOp(+)
  Number(2)
  Number(3)
himu23@ideapad3:~/Desktop/projects/soc-now-u-