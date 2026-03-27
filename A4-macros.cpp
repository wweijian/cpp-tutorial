#define HELLO "Hello, World!"
#define NUMBER 42
#define SQUARE(x) ((x) * (x))
#define FUNC(x) hello(&x)

#ifdef DEBUG_PRINT
#define DEBUG std::cout
#else
#define DEBUG if (false) std::cout
#endif

#define MULTILINE do { 															\
	std::cout << "This is a multi-line macro." << std::endl;					\
	std::cout << "It can contain multiple statements." << std::endl;			\
} while (0)

#include <iostream>

void hello(void *ptr) {
	(void)ptr;
	std::cout << "HELLLLLO" << std::endl;
}

int main ()
{
	// HELLO: simple string constant macro
	std::cout << HELLO << std::endl;

	// NUMBER: simple integer constant macro
	std::cout << NUMBER << std::endl;

	// SQUARE(x): function-like macro
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(3 + 2) << std::endl;  // safe because of extra parens

	// FUNC(x): passes address of variable to hello()
	int x = 10;
	FUNC(x);

	// DEBUG: conditional debug output (active only if DEBUG_PRINT is defined)
	DEBUG << "Debug message" << std::endl;

	// MULTILINE: multi-statement macro wrapped in do-while
	MULTILINE;

	return (0);
}
