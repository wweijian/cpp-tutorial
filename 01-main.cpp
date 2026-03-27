#include <iostream>
#include "01-constructors.hpp"

void test_construction() {
	std::cout	<< "=== Construction ===\n";
	MyClass obj1;
	std::cout	<< "default  — num: " << obj1.get_num()
				<< ", str: " << obj1.get_str()
				<< ", const_str: " << obj1.get_const_str() << "\n";

	MyClass obj2(42, "Hello");
	std::cout	<< "param    — num: " << obj2.get_num()
				<< ", str: " << obj2.get_str()
				<< ", const_str: " << obj2.get_const_str() << "\n"
				<< std::endl;
}

void test_copy() {
	std::cout	<< "=== Copy constructor / assignment ===\n";
	MyClass obj2(42, "Hello");

	MyClass obj3(obj2);
	std::cout	<< "copy     — num: " << obj3.get_num()
				<< ", str: " << obj3.get_str() << "\n";

	obj3.set_num(99);
	obj3.set_str("Modified");
	std::cout	<< "original — num: " << obj2.get_num()
				<< ", str: " << obj2.get_str()
				<< " (unchanged after mutating copy)\n";

	MyClass obj1;
	obj1 = obj2;
	std::cout	<< "assigned — num: " << obj1.get_num()
				<< ", str: " << obj1.get_str()
				<< ", const_str: " << obj1.get_const_str() << "\n"
				<< std::endl;
}

void test_setters() {
	std::cout	<< "=== Setters ===\n";
	MyClass obj(42, "Hello");
	obj.set_num(100);
	obj.set_str("World");
	std::cout	<< "after setters — num: " << obj.get_num()
				<< ", str: " << obj.get_str()
				<< ", const_str: " << obj.get_const_str() << "\n"
				<< std::endl;
}

void test_const_method() {
	std::cout	<< "=== Const method (do_nothing) ===\n";
	MyClass obj;
	obj.do_nothing("This string will not be modified.");
	std::cout << std::endl;
}

void test_static() {
	std::cout	<< "=== Static function / variable ===\n";
	MyClass::static_function();
	std::cout	<< "static_const_num: " << MyClass::static_const_num << "\n"
				<< std::endl;
}

int main() {
	test_construction();
	test_copy();
	test_setters();
	test_const_method();
	test_static();
	return 0;
}

/* 
	notes:

	i typically write my tests in functions
	so that i can comment out whenever i want for visibility
	it also tells the evaluator exactly what you're testing too
	you can refactor the tests into a separate file if you prefer

*/
