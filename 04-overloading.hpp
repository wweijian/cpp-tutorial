#pragma once

#include <cctype>
#include <iostream>

class FTString {
	public:
		FTString();
		FTString(const char* str); // (0)
		FTString(const FTString& other);
		FTString& operator=(const FTString& other);
		~FTString();
		
		/* operator overloads */
		FTString operator+(const FTString& other) const; // (1)
		FTString operator+(const char* str) const;
		FTString& operator++(); // (2)
		FTString  operator++(int);
		FTString operator*(int times) const;
		FTString operator-() const ; // (3)
		void operator>>(int &i) const;
		void operator>>(unsigned int &u) const;
		// (4)
		
		/* access overloads */
		char	operator[](size_t index) const;
		size_t	operator[](char c) const;
		char*	operator[](const char *str) const;

		/* boolean overloads */
		bool operator==(const FTString& other) const; // (5)
		bool operator!=(const FTString& other) const;
		bool operator>(const FTString& other) const;
		bool operator<(const FTString& other) const;
		bool operator>=(const FTString& other) const;
		bool operator<=(const FTString& other) const;

		/* function overloads */
		void ft_print() const; // (6)
		void ft_print(int times) const;

		/* methods */
		char* c_str() const;
		size_t length() const;

	private:
		char*	str;
		size_t	len;
		void	replace_str(const char* s, size_t new_len);
};

std::ostream& operator<<(std::ostream& os, const FTString& obj); // (7)

/* 
	notes:

	what is an overload?
	overloading is using the same function name or operators
	and differing only by the parameters or the return type
	cpp checks at run time which function to call based on the arguments passed to the function

	(0)
	this is an example of constructor overloading

	(1)
	this is an example of operator overloading
	operator overloads are quite tricky to implement at the start
	they have their own syntax and rules that you have to follow
	like you can't just have 10 arguments for a operator+, they will not accept it

	(2)
	prefix and postfix overload

	(3)
	unary operator overload

	(4)
	other overlaods include:
		unary operators: ++, --, -, !
		binary operators: +, -, *, /, %, <<, >>, [], etc.
		comparison operators: ==, !=, >, <, >=, <=
		assignment operators: =, +=, -=, *=, /=, %=, <<=, >>=, &=, |=, ^=
		bitwise operators: &, |, ^, ~, <<, >>
		access operators: [], (), ->
		there are also some special operators that you can overload like the function call operator ()

		list is not exhaustive but is more than sufficient

	(5)
	boolean operator overloads

	(6)
	function overloads

	(7)
	please note the function overload on how to print the object
	and also see how it does not belong to the class
	why? because we are adding a way to how ostream takes in the object
*/

