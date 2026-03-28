# C++ Tutorial

A collection of C++ examples compiled with strict C++98 flags.

## Topics

| Target | File(s) | Topic |
|--------|---------|-------|
| `00` | `00-print.cpp` | Hello World |
| `01` | `01-main.cpp`, `01-constructors.cpp` | Constructors, destructors, Orthodox Canonical Form |
| `02` | `02-references.cpp` | References and pointers |
| `03` | `03-control-flow.cpp` | Control flow (for, switch, ternary, scope) |
| `04` | `04-main.cpp`, `04-overloading.cpp` | Operator overloading (FTString) |
| `05` | `05-main.cpp`, `05-inheritance.cpp` | Inheritance |
| `06` | `06-main.cpp`, `06-polymorphism.cpp` | Polymorphism and abstract classes |
| `A0` | `A0-string.cpp` | `std::string` |
| `A1` | `A1-iostream.cpp` | `iostream` (cin / cout) |
| `A2` | `A2-stringstream.cpp` | `stringstream` |
| `A3` | `A3-fstream.cpp` | File I/O (`fstream`) |
| `A4` | `A4-macros.cpp` | Preprocessor macros |
| `A5` | `A5-namespace-and-friends.cpp` | Namespaces and friend classes |

**Makefile.example:** an example on how to write you can write your Makefile

## Usage

```sh
make <target>
```

For example:

```sh
make 06
./a.out
```

## Build flags

```
-Wall -Werror -Wextra -pedantic -std=c++98
```
