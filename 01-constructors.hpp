#pragma once 										// (0)

#include <string>

class MyClass { 									// (1)
	public:
		/* constructors, destructor, and assignment operator */
		MyClass();									// default constructor (2)
		MyClass(int n, const std::string& s);		// parameterized constructor (3)
		MyClass(const MyClass& other);				// copy constructor (4)	
		MyClass& operator=(const MyClass& other);	// copy assignment operator (5)
		~MyClass(); // destructor (6)
		
		/* methods */
		int 				get_num() const ;			// (7)
		std::string 		get_str() const ;
		const std::string 	get_const_str() const ;
		void				set_num(int n);			// (8)
		void				set_str(const std::string& s);
		// void 				set_const_str(const std::string& s); // (9)
		void 				do_nothing(const std::string& s) const ; // (10)
		static void 		static_function();			// (11)

		/* variables */
		static const int 	static_const_num;		// (12)

	private: // (13)
		/* variables */
		int 				num;
		std::string 		str;
		const std::string 	const_str;

		/* function */
		void 				replace_str(char *new_str);

} ; // (14)

/*
	notes: 

	(0):
	you can use #ifndef #define if you prefer
	i'm lazy, so i mostly use #pragma once,
	which is supported by all major compilers

	(1):
	class declaration must be in PascalCase 
	any file containing a class should also be in PascalCase
	try to stick to one class per hpp
	avoid having code in the header file, 42 doesn't allow that if i'm not wrong
	irl, you might throw one liners in here

	member variables and functions should be in camelCase
	but i don't think 42 specifies this 

	(2) & (3):
	you can have any number of parameterized constructors, but only one default constructor
	you should also have destructor
	constructor does what it says on the tin, it constructs the object
	constructors need to be public if you want it to be accessed outside of the class
	it can however be private, if it does not need to be instantiated outside of the class

	(4):
	copy constructor is required for OCF (cpp02+)
	you can still see the implementation in the cpp file

	(5):
	copy assignment operator is required for OCF (cpp02+)
	you can still see the implementation in the cpp file
	but more on it in the overload section

	(6):
	destructor is required for OCF (cpp02+)
	it also does what it says on the tin, it destructs the object
	or in other words, it cleans up any resources the object may have acquired during its lifetime

	(7) & (8):
	getters and setters are required for some exercises (read the subject)
	they are nothing more than getting and setting variables, which are private,
	without lending access direct access to the variable itself

	(9):
	can't have setters for const members, as they cannot be modified after construction

	(10):
	const keywords
	const before a function refers to the return type
	const before a paramter prevents the function from trying to change the data type
	const after means that you cannot change any variables within the data type

	(11) & (12):
	static functions and variables are shared among all instances of the class
	they are not tied to any specific instance, but rather belong to the class itself
	as we will see in main how they are accessed

	(13):
	all members are private by default unless specified otherwise
	i prefer expclicitly stating it
	the order doesn't matter

	(14):
	end of class declaration, don't forget the semicolon

*/

