#pragma once

#include <string>

class Base { // (0)
	public:
		Base();
		Base(const std::string& str);
		Base(const Base& other);
		Base& operator=(const Base& other);
		virtual ~Base(); // (1)

		virtual void public_function1(); 
		virtual void public_function2();
		void non_virtual_function();
		std::string public_variable1;
		std::string public_variable2;

	protected: // (2)
		virtual void protected_function1();
		virtual void protected_function2();
		std::string protected_variable1;
		std::string protected_variable2;

	private:
		virtual void private_function1(); // (3)
		virtual void private_function2();
		std::string private_variable1;
		std::string private_variable2;
};

class PublicDerived : public Base { // (4)
	public:
		PublicDerived();
		PublicDerived(const PublicDerived& other);
		PublicDerived& operator=(const PublicDerived& other);
		~PublicDerived();

		void public_function2();
		std::string public_variable2;

	protected:
		void protected_function2();
		std::string protected_variable2;

	private:
		void private_function2();
		std::string private_variable2;
};

class ProtectedDerived : protected Base { // (5)
	public:
		ProtectedDerived();
		~ProtectedDerived();

		void public_function2();
		std::string public_variable2;

	protected:
		void protected_function2();
		std::string protected_variable2;

	private:
		void private_function2();
		std::string private_variable2;
};

class PrivateDerived : private Base { // (6)
	public:
		PrivateDerived();
		~PrivateDerived();

		void public_function2();
		std::string public_variable2;

	protected:
		void protected_function2();
		std::string protected_variable2;

	private:
		void private_function2();
		std::string private_variable2;
};

class OtherDerived1 : virtual public Base { // (7) 
	public:
		OtherDerived1();
		~OtherDerived1();

		std::string public_variable2;
		void public_function2();
};

class OtherDerived2 : virtual public Base {
	public:
		OtherDerived2();
		~OtherDerived2();

		std::string public_variable2;
		void public_function2();
};

class DiamondDerived : public OtherDerived1, public OtherDerived2 { // (8)
	public:
		DiamondDerived();
		~DiamondDerived();

		void public_function2();
		std::string public_variable2;

	protected:
		std::string protected_variable2;

	private:
		std::string private_variable2;
};

class HidingDerived : public Base // (9)
{
	public:
		HidingDerived();
		~HidingDerived();

		void non_virtual_function(int x);
};

/*
	notes:

	inheritance has an "is-a" relationship
	vs a variable which has a "has-a" relationship
	inheriting more than one has a "is-a-and-a" relationship

	in this example, derived is a base, but a base is not a derived (non-commutative)

	other examples include:
		- a car is a vehicle
		- a dog is an animal
		- a square is a shape
		- a bat is a mammal and is a winged animal

	C++ resolves the Diamond Problem using virtual inheritance.
	Virtual inheritance ensures that only one shared instance of the base class exists
	regardless of how many times it is inherited.

	(0)
	a base class is just a regular class that other classes inherit from
	it defines common properties and behaviors that derived classes can reuse or override
	you don't need to do anything special to make a class a base class,
	it becomes one the moment something inherits from it

	(1)
	virtual ~Base() ensures that when you delete a derived object through a base pointer,
	the derived destructor runs first, then the base destructor
	without virtual, only the base destructor runs — the derived part leaks

	(2)
	protected is between public and private
	public: anyone can access it
	protected: only the class itself and its derived classes can access it
	private: only the class itself can access it
	use protected for things you want derived classes to use, but not expose to the outside world

	(3)
	virtual tells the compiler to use dynamic dispatch (runtime polymorphism)
	meaning the actual function called depends on the real type of the object,
	not the type of the pointer or reference
	without virtual, the function called is decided at compile time based on the pointer type
	this is the core mechanism behind polymorphism, which we will explore later

	(4)
	public inheritance is the most common form
	Base's public members stay public in Derived
	Base's protected members stay protected in Derived
	Base's private members are still inherited but not accessible directly

	(5)
	protected inheritance: Base's public members become protected in Derived
	so the outside world can no longer treat Derived as a Base
	only Derived and its children can still see what was public in Base
	rarely used, but useful when you want to inherit implementation without exposing the interface

	(6)
	private inheritance: everything from Base becomes private in Derived
	neither the outside world nor any further derived classes can see Base's members
	the "is-a" relationship is completely severed — Derived is no longer usable as a Base
	think of it as "implemented-in-terms-of" rather than "is-a"

	(7)
	without virtual inheritance, DiamondDerived would inherit two separate copies of Base
	one from OtherDerived1 and one from OtherDerived2, causing ambiguity
	virtual inheritance tells the compiler to share a single Base instance across all paths
	both OtherDerived1 and OtherDerived2 mark their inheritance as virtual public Base
	DiamondDerived will have to construct its own base

	(8)
	DiamondDerived inherits from both OtherDerived1 and OtherDerived2
	the comma-separated list after the colon is multiple inheritance syntax
	because both parents used virtual inheritance, there is only one shared Base underneath
	DiamondDerived is responsible for constructing the virtual Base directly

	(9)
	HidingDerived has non_virtual_function(int x) — a different signature from Base's non_virtual_function()
	since neither is virtual, this is not an override — it is hiding
	the derived version with (int x) shadows the base version with no arguments
	if you call obj.non_virtual_function() on a HidingDerived it won't compile,
	because the no-argument version is hidden by the derived class's version

	see more:
	- final (C++11)
	- override (C++11)
	- "using" to restore access of member class
	- rule of three: if you define any of destructor, copy constructor, or copy assignment,
	  you should define all three
*/

/* 
	summary table:
	Base Member Access	public Inheritance	protected Inheritanc	private Inheritance
	public				public				protected				private
	protected			protected			protected				private
	private				inaccessible		inaccessible			inaccessible
*/
