#include <iostream>
#include "05-inheritance.hpp"

void test_constructor_destructor_order() // (0)
{
	std::cout << "=== Constructor / Destructor Order ===" << std::endl;
	PublicDerived pd;
	std::cout << pd.public_variable1 << std::endl;
	std::cout << std::endl;
}

void test_virtual_dispatch() //(1)
{
	std::cout << "=== Virtual Dispatch ===" << std::endl;
	Base* b = new PublicDerived();
	b->public_function1();
	b->public_function2();
	delete b;
	std::cout << std::endl;
}

void test_override_vs_inherited() // (2)
{
	std::cout << "=== Override vs Inherited ===" << std::endl;
	PublicDerived pd;
	pd.public_function1();
	pd.public_function2();

	Base& ref = pd;
	ref.public_function1();
	ref.public_function2();
	std::cout << std::endl;
}

void test_public_inheritance_access() // (3)
{
	std::cout << "=== Public Inheritance Access ===" << std::endl;
	PublicDerived pd;
	std::cout << pd.public_variable1 << std::endl;
	std::cout << pd.public_variable2 << std::endl;
	std::cout << std::endl;
}

void test_protected_inheritance_access() // (4)
{
	std::cout << "=== Protected Inheritance Access ===" << std::endl;
	ProtectedDerived prd;
	std::cout << prd.public_variable2 << std::endl;
	std::cout << std::endl;
}

void test_private_inheritance_access() // (5)
{
	std::cout << "=== Private Inheritance Access ===" << std::endl;
	PrivateDerived pvd;
	std::cout << pvd.public_variable2 << std::endl;
	std::cout << std::endl;
}

void test_diamond_problem() // (6)
{
	std::cout << "=== Diamond Problem ===" << std::endl;
	DiamondDerived dd;
	dd.public_function2();
	std::cout << dd.public_variable1 << std::endl;
	std::cout << std::endl;
}

void test_hiding() // (7)
{
	std::cout << "=== Hiding vs Overriding ===" << std::endl;
	HidingDerived hd;
	hd.non_virtual_function(42);
	hd.Base::non_virtual_function();

	Base* b = new HidingDerived();
	b->non_virtual_function();
	delete b;
	std::cout << std::endl;
}

void test_copy_construction() // (9)
{
	std::cout << "=== Copy Construction and Assignment ===" << std::endl;
	PublicDerived pd1;
	PublicDerived pd2 = pd1;    // copy constructor
	PublicDerived pd3;
	pd3 = pd1;                  // copy assignment operator
	std::cout << std::endl;
}

void test_object_slicing() // (8)
{
	std::cout << "=== Object Slicing ===" << std::endl;
	PublicDerived pd;
	Base b = pd;
	b.public_function2();
	std::cout << std::endl;
}

int main()
{
	test_constructor_destructor_order();
	test_virtual_dispatch();
	test_override_vs_inherited();
	test_public_inheritance_access();
	test_protected_inheritance_access();
	test_private_inheritance_access();
	test_diamond_problem();
	test_hiding();
	test_copy_construction();
	test_object_slicing();

	return 0;
}

/*
	notes:

	(0)
	shows the order: Base constructor runs first, then Derived constructor
	on destruction the order reverses: Derived destructor runs first, then Base
	to access what is not directly in your derived class
	you can simply just write like line 8,
	just point directly to it from your derived class
	test yourself: what happens if the destructor is not virtual —

	(1)
	virtual dispatch means when you call the function
	the compiler decides which version to runbased on the vtable

	public_function1 is not overridden in PublicDerived, so Base's version runs
	public_function2 is overridden, so PublicDerived's version runs even through the Base pointer
	
	delete b calls ~PublicDerived then ~Base because ~Base is virtual
	test yourself: what would happen if ~Base were not virtual — only ~Base would run

	(2)
	calls the same two functions in two ways: directly on a PublicDerived object,
	and through a Base reference
	both produce the same result because references use virtual dispatch just like pointers
	public_function1 runs Base's version either way (not overridden)
	public_function2 runs PublicDerived's version either way (overridden)
	test yourself: a case where the two differ — they won't for virtual functions

	(3)
	accesses public_variable1 and public_variable2 through a PublicDerived object
	public_variable1 comes from Base and is accessible because public inheritance
	keeps Base's public members public in Derived
	public_variable2 is defined in both — pd.public_variable2 refers to Derived's own copy
	test yourself: accessing protected_variable1 or private_variable1 from here — the compiler will refuse

	(4)
	accesses public_variable2 through a ProtectedDerived object
	this is ProtectedDerived's own public_variable2, not Base's
	Base's public_variable1 is not accessible from outside — protected inheritance
	demoted it to protected inside ProtectedDerived
	test yourself: using a ProtectedDerived where a Base* is expected — that won't compile

	(5)
	same structure as (4) but with PrivateDerived
	pvd.public_variable2 is the one PrivateDerived itself declared public
	everything inherited from Base is now private inside PrivateDerived —
	not accessible to the outside world and not accessible to any further derived classes
	test yourself: using a PrivateDerived where a Base* is expected — that won't compile

	(6)
	creates a DiamondDerived and accesses public_variable1 and calls public_function2
	public_variable1 comes from the single shared Base instance —
	if virtual inheritance were not used, this line would be ambiguous and fail to compile
	public_function2 is DiamondDerived's own version
	test yourself: the ambiguity error itself — the code is already written with virtual inheritance

	(7)
	demonstrates three things in one function:
	hd.non_virtual_function(42) calls HidingDerived's version — the one with an int parameter
	hd.Base::non_virtual_function() explicitly bypasses hiding and calls Base's version
	b->non_virtual_function() calls Base's version because the function is not virtual —
	the pointer type (Base*) decides which version runs, not the real type
	test yourself: an actual override — that requires virtual, which non_virtual_function does not have

	(8)
	copies a PublicDerived into a Base by value: Base b = pd
	b.public_function2() calls Base's version, not PublicDerived's
	because b is a plain Base object — the derived part was sliced off during the copy
	virtual dispatch only works through pointers and references, not through value copies
	test yourself: recovering the sliced data — it is gone

	(9)
	pd2 = pd1 invokes PublicDerived's copy constructor, which calls Base(other) first
	then copies PublicDerived's own members
	pd3 = pd1 invokes the copy assignment operator, which calls Base::operator=(other) first
	the key rule: always delegate to the base version so the base subobject is not forgotten
	test yourself: remove Base(other) from the copy constructor and check what public_variable1 holds

	Question:
	why not enum? 
	enum can also show the is-a relationship
*/
