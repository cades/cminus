-include plateform_dependent.mk
TARGET = parser
OBJECT = parser.tab.c parser.tab.h parser.tab.o lex.yy.c parser.output main.o test
CC = g++ -Wno-write-strings -g
LEX = flex
YACC = bison -v
YACCFLAG = -d
LIBS = -lfl 
TEST_LIBS    :=  -lCppUTest -L$(CPPUTEST_INSTALL_PATH)/lib
TEST_INCLUDE :=  -I$(CPPUTEST_INSTALL_PATH)/include

#ALL_AST_SRCS := $(wildcard node/Debug/*.o)
#AST_SRCS     := $(filter-out %Test.o, $(ALL_AST_SRCS))
AST_SRCS      := AST/Debug/Node/*.o AST/Debug/Node/Iterator/*.o AST/Debug/Visitor/*.o AST/Debug/Visitor/*/*.o AST/Debug/SymbolTable/*.o AST/Debug/SymbolTable/*/*.o
parser: parser.tab.o main.o
	$(CC) -o $(TARGET) parser.tab.o main.o $(AST_SRCS) $(LIBS)

parser.tab.o: parser.tab.c lex.yy.c
	$(CC) -c parser.tab.c

lex.yy.c: lexer3.l
	$(LEX) lexer3.l

parser.tab.c: parser.y 
	$(YACC) $(YACCFLAG) parser.y

clean:
	rm -f $(TARGET) $(OBJECT) 

test: parser.tab.o
	$(CC) -o test parser.tab.o IntegrationTesting/*Test.cpp $(AST_SRCS) $(LIBS) $(TEST_LIBS) $(TEST_INCLUDE)

main.o: main.cpp
	$(CC) -c main.cpp
