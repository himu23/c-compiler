# soc-now-u-c-me
I am doing the project "Now You C Me – Build Your Own C Compiler" under Aditya Sanapala as mentor as part of SoC 2025. The project is about understanding how compilers work and trying to build a working compiler for a simplified version of C called C--. Each week had structured tasks and resources which I followed. I also referred to a few extra tutorials and blogs for better understanding of compiler phases. My week-wise learning is as follows:
Week 1:

Compiler Architecture: I learnt the different stages of a compiler – lexical analysis, parsing, semantic analysis etc.

Lexical Analysis: I implemented a lexer in C++ that identifies keywords, identifiers, operators, literals, delimiters etc. and gives output with token type, value, and line-column position.

Tokenizer Output: I wrote a small program to read a C-- file, tokenize it, and print tokens in a readable format.

Project Structure & Build: I set up a basic folder structure (src/, tests/) and wrote a Makefile with make, make test, make clean commands for build automation and testing.


Week 2:

Parsing Concepts: I learnt about context-free grammars, BNF notation, recursive descent parsing and how abstract syntax trees (ASTs) differ from parse trees.

C-- Grammar: I wrote the grammar of C-- in BNF format using constructs like declaration, expression, statement, loops etc.

AST Node Classes: I created base and derived classes in C++ for different types of nodes like IfStmt, ReturnStmt, BinaryOp, Number, Variable etc.

Recursive Descent Parser: I implemented parsing functions for major grammar rules and built the AST from the token stream. I also added error handling and sync functions for parser recovery.

AST Printing: I wrote code to pretty-print the AST and used it to debug and verify parsing outputs of small programs.

check readme files in weekwise folders