#include "04-overloading.hpp"
#include <iostream>

void test_construction() {
	std::cout << "=== Construction ===\n";
	FTString a("hello");
	FTString b(a);
	FTString c;
	c = a;
	std::cout << a << "\n\n";
	std::cout << b << "\n\n";
	std::cout << c << "\n\n";
	std::cout << "\n";
}

void test_concatenation() {
	std::cout << "=== Concatenation (operator+) ===\n";
	FTString a("hello");
	FTString b("world");
	(a + FTString(" ") + b).ft_print(); // hello world
	(a + " world").ft_print();			// hello world
	std::cout << "\n";
}

void test_increment() {
	std::cout << "=== Increment (operator++) ===\n";
	FTString pre("hello");
	FTString& ref = ++pre;
	std::cout << "prefix  — pre: "; pre.ft_print(); // HELLO
	std::cout << "prefix  — ref: "; ref.ft_print(); // HELLO (same object)

	FTString post("hello");
	FTString old = post++;
	std::cout << "postfix — old: "; old.ft_print(); 	// hello
	std::cout << "postfix — post: "; post.ft_print(); 	// HELLO
	std::cout << "\n";
}

void test_arithmetic() {
	std::cout << "=== Arithmetic (operator*, unary -) ===\n";
	(FTString("ab") * 3).ft_print();	// ababab
	(-FTString("abcde")).ft_print();	// edcba
	std::cout << "\n";
}

void test_extraction() {
	std::cout << "=== Extraction (operator>>) ===\n";
	FTString num("42");
	int i;
	unsigned int u;
	num >> i;
	num >> u;
	std::cout << "int: " << i << "\n";
	std::cout << "unsigned int: " << u << "\n";
	std::cout << "\n";
}

void test_access() {
	std::cout << "=== Access (operator[]) ===\n";
	FTString s("hello");
	std::cout << "s[0]=" << s[(size_t)0] << " s[1]=" << s[(size_t)1] << " s[4]=" << s[(size_t)4] << "\n";

	std::cout << "count of 'l' in \"hello\": " << s['l'] << "\n"; // 2
	std::cout << "count of 'z' in \"hello\": " << s['z'] << "\n"; // 0

	FTString haystack("hello world");
	char* found = haystack["world"];
	std::cout << "strstr(\"hello world\", \"world\")=" << (found ? found : "not found") << "\n"; // world
	char* missing = haystack["xyz"];
	std::cout << "strstr(\"hello world\", \"xyz\")=" << (missing ? missing : "not found") << "\n"; // not found
	std::cout << "\n";
}

void test_comparison() {
	std::cout << "=== Comparison ===\n";
	FTString x("apple"), y("banana"), z("apple");
	std::cout << "apple == apple : " << (x == z) << "\n";
	std::cout << "apple != banana: " << (x != y) << "\n";
	std::cout << "apple <  banana: " << (x <  y) << "\n";
	std::cout << "banana > apple : " << (y >  x) << "\n";
	std::cout << "apple <= apple : " << (x <= z) << "\n";
	std::cout << "apple >= apple : " << (x >= z) << "\n";
	std::cout << "\n";
}

void test_print() {
	std::cout << "=== ft_print overloads ===\n";
	FTString s("hi");
	s.ft_print();
	s.ft_print(3);
	std::cout << "\n";
}

int main() {
	test_construction();
	test_concatenation();
	test_increment();
	test_arithmetic();
	test_extraction();
	test_access();
	test_comparison();
	test_print();
	return 0;
}
