CC			= c++
CXXFLAGS 	= -Wall -Werror -Wextra -pedantic -std=c++98

.PHONY: all 00 01 02 03 04 05 06 A0 A1 A2 A3 A4 A5

all:
	@echo "Usage: make <target>"
	@echo ""
	@echo "  00  -  Hello World"
	@echo "  01  -  Constructors, destructors, OCF"
	@echo "  02  -  References and pointers"
	@echo "  03  -  Control flow (for, switch, ternary, scope)"
	@echo "  04  -  Operator overloading (FTString)"
	@echo "  05  -  Inheritance"
	@echo "  06  -  Polymorphism and abstract classes"
	@echo "  A0  -  std::string"
	@echo "  A1  -  iostream (cin / cout)"
	@echo "  A2  -  stringstream"
	@echo "  A3  -  fstream (file I/O)"
	@echo "  A4  -  Preprocessor macros"
	@echo "  A5  -  Namespaces and friend classes"

00:
	$(CC) $(CXXFLAGS) 00-print.cpp

01:
	$(CC) $(CXXFLAGS) 01-main.cpp 01-constructors.cpp

02:
	$(CC) $(CXXFLAGS) 02-references.cpp

03:
	$(CC) $(CXXFLAGS) 03-control-flow.cpp

04:
	$(CC) $(CXXFLAGS) 04-main.cpp 04-overloading.cpp

05:
	$(CC) $(CXXFLAGS) 05-main.cpp 05-inheritance.cpp

06:
	$(CC) $(CXXFLAGS) 06-main.cpp 06-polymorphism.cpp

A0:
	$(CC) $(CXXFLAGS) A0-string.cpp

A1:
	$(CC) $(CXXFLAGS) A1-iostream.cpp

A2:
	$(CC) $(CXXFLAGS) A2-stringstream.cpp

A3:
	$(CC) $(CXXFLAGS) A3-fstream.cpp

A4:
	$(CC) $(CXXFLAGS) A4-macros.cpp

A5:
	$(CC) $(CXXFLAGS) A5-namespace-and-friends.cpp
