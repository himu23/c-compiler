himu23@ideapad3:~/Desktop/projects/soc-now-u-c-me/week 1/c-minus-compiler$ echo "int main return 42" > tests/sample_programs/test1.c--
himu23@ideapad3:~/Desktop/projects/soc-now-u-c-me/week 1/c-minus-compiler$ make
make run
g++ -std=c++17 -Wall src/main.cpp src/lexer.cpp -o lexer
./lexer tests/sample_programs/test1.c--
Token: 0 (int) at line 1, col 1
Token: 1 (main) at line 1, col 5
Token: 0 (return) at line 1, col 10
Token: 2 (42) at line 1, col 17
Token: 5 (EOF) at line 2, col 2