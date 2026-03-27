#include "01-constructors.hpp"
#include <iostream> // (0)

// constructors
MyClass::MyClass() // (1)
	:	num(0),
		str("const"),
		const_str("const") // (2)
{}

MyClass::MyClass(int n, const std::string& s)
	:	num(n),
		str(s),
		const_str(s)
{}

MyClass::MyClass(const MyClass& other) // (3)
	:	num(other.num),
		str(other.str),
		const_str(other.const_str)
{}

MyClass& MyClass::operator=(const MyClass& other) {
	if (this != &other) { // (4)
		num = other.num;
		str = other.str;
		// const_str = other.const_str; // (5)
	}
	return *this;
}
MyClass::~MyClass() {} // destructor

// static member definition
const int MyClass::static_const_num = 42; // (6)

// methods
int MyClass::get_num() const {
	return num;
}

std::string MyClass::get_str() const {
	return str;
}

const std::string MyClass::get_const_str() const { // (7)
	return const_str;
}

void MyClass::set_num(int n) {
	num = n;
}

void MyClass::set_str(const std::string& s) {
	str = s;
}

void MyClass::do_nothing(const std::string& s) const {
	// s = "This string will not be modified."; (8)
	std::cout << s << std::endl;
}

void MyClass::static_function() {
	std::cout << "This is a static function." << std::endl;
}

/*
	notes:

	(0):
	you can include the header file in the hpp file instead
	but it creates compilation overhead

	(1):
	all functions and variables defined in the .cpp must begin with MyClass::
	you will find that if you do not do so, you cannot compile

	(2):
	this is how i typically write my initilizer list,
	as long as they are delimited by commas except for the last one
	
	important: const members must be initialized in the initializer list
	as default constructors will be called if not included in the intializer list
	and const members cannot be reassigned to after construction
	see line 20

	in fact for default constructors you don't even have to specify
	they just use the default values of each class

	(3):
	copy constructors typically you just take the values directly from the other object
	keep in mind that you're the same class
	so you have access to the private members of the other object

	(4):
	this checks for self assignment
	it doesn't really matter, just saves you some time
	observe the syntax of the copy constructor
	see where the const values are
	and what are being returned

	(5):
	const members cannot be modified after construction, so they cannot be assigned to in the copy assignment operator

	(6):
	once declared here, it'll not change for the lifetime of the program

	(7):
	every const and keyword in the function signature in the hpp 
	must also be included in the cpp, otherwise it will be considered a different function
	static on the other hand is not part of the function signature
	so it is omitted in the cpp

	(8):
	const strings can't be modified here, just an example
*/
