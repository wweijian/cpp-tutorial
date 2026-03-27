#include <iostream>
#include "06-polymorphism.hpp"

void test_cannot_instantiate() // (0)
{
	std::cout << "=== Cannot Instantiate Abstract Classes ===" << std::endl;

	// APhone has pure virtual call() — cannot instantiate
	// APhone a("black", 128, 8);

	// IOperatingSystem is a pure interface — cannot instantiate
	// IOperatingSystem* iface = new IOperatingSystem();

	// iOS still has pure virtual version() — cannot instantiate
	// iOS i;

	// android still has pure virtual version() — cannot instantiate
	// android a;

	// Apple inherits unimplemented call() and version() — cannot instantiate
	// Apple apple("silver", 256, 8);

	// Samsung inherits unimplemented call() and version() — cannot instantiate
	// Samsung samsung("black", 256, 8);

	std::cout << "(see comments — none of the above compile)" << std::endl;
	std::cout << std::endl;
}

void test_concrete_instantiation() // (1)
{
	std::cout << "=== Concrete Instantiation ===" << std::endl;
	iPhone16  ip16("black", 128, 8);
	iPhone17  ip17("white", 256, 8);
	GalaxyS24 s24("blue",   256, 12);
	GalaxyS25 s25("gray",   512, 12);
	std::cout << std::endl;
}

void test_aphone_dispatch() // (2)
{
	std::cout << "=== Virtual Dispatch Through APhone* ===" << std::endl;
	APhone* phones[4];
	phones[0] = new iPhone16("black", 128, 8);
	phones[1] = new iPhone17("white", 256, 8);
	phones[2] = new GalaxyS24("blue",  256, 12);
	phones[3] = new GalaxyS25("gray",  512, 12);

	for (int i = 0; i < 4; i++)
		phones[i]->call("555-1234");

	for (int i = 0; i < 4; i++)
		delete phones[i];
	std::cout << std::endl;
}

void test_ios_dispatch() // (3)
{
	std::cout << "=== Virtual Dispatch Through IOperatingSystem* ===" << std::endl;
	IOperatingSystem* systems[4];
	systems[0] = new iPhone16("black", 128, 8);
	systems[1] = new iPhone17("white", 256, 8);
	systems[2] = new GalaxyS24("blue",  256, 12);
	systems[3] = new GalaxyS25("gray",  512, 12);

	for (int i = 0; i < 4; i++)
	{
		systems[i]->printInfo();
		systems[i]->version();
	}

	for (int i = 0; i < 4; i++)
		delete systems[i];
	std::cout << std::endl;
}

void test_two_interfaces() // (4)
{
	std::cout << "=== One Object, Two Interface Pointers ===" << std::endl;
	iPhone16 phone("gold", 256, 8);

	APhone*           as_phone = &phone;
	IOperatingSystem* as_os    = &phone;

	as_phone->call("555-9999");
	as_os->printInfo();
	as_os->version();

	// as_phone->printInfo();    // compile error: APhone has no printInfo
	// as_os->call("555-9999");  // compile error: IOperatingSystem has no call

	std::cout << std::endl;
}

void test_virtual_destructor() // (5)
{
	std::cout << "=== Virtual Destructor ===" << std::endl;
	APhone* p = new iPhone16("red", 128, 6);
	delete p;
	std::cout << std::endl;
}

void test_dynamic_cast() // (6)
{
	std::cout << "=== Dynamic Cast ===" << std::endl;
	APhone* p1 = new iPhone16("pink",   128, 8);
	APhone* p2 = new GalaxyS24("green", 256, 12);

	iPhone16* ip = dynamic_cast<iPhone16*>(p1);
	if (ip)
		std::cout << "p1 is an iPhone16 — cast succeeded" << std::endl;

	iPhone16* fail = dynamic_cast<iPhone16*>(p2);
	if (!fail)
		std::cout << "p2 is not an iPhone16 — cast returned nullptr" << std::endl;

	delete p1;
	delete p2;
	std::cout << std::endl;
}

void test_cross_interface_dynamic_cast() // (7)
{
	std::cout << "=== Cross-Interface Access Via Dynamic Cast ===" << std::endl;
	APhone* p = new iPhone16("black", 128, 8);

	// p->printInfo();  // compile error: APhone* has no printInfo

	IOperatingSystem* as_os = dynamic_cast<IOperatingSystem*>(p);
	if (as_os)
	{
		as_os->printInfo();
		as_os->version();
	}

	delete p;
	std::cout << std::endl;
}

int main()
{
	test_cannot_instantiate();
	test_concrete_instantiation();
	test_aphone_dispatch();
	test_ios_dispatch();
	test_two_interfaces();
	test_virtual_destructor();
	test_dynamic_cast();
	test_cross_interface_dynamic_cast();

	return 0;
}

/*
	notes:

	(0)
	a class is abstract if it has at least one pure virtual function (= 0)
	mid-hierarchy classes like Apple and Samsung are also abstract —
	they do not implement every pure virtual inherited from their parents
	you can hold pointers and references to abstract types, just not objects
	test yourself: uncomment any one line above and watch the compiler refuse

	(1)
	iPhone16/17 and GalaxyS24/25 are the only concrete classes in this hierarchy
	they implement every pure virtual from every base class in their chain
	the constructor output traces the full build order from base down to leaf
	test yourself: trace the exact constructor chain printed for GalaxyS25

	(2)
	APhone* can see only what APhone declares: call()
	the vtable routes the call to the real type at runtime — that is virtual dispatch
	delete through APhone* is safe because ~APhone is virtual
	test yourself: what happens if ~APhone were not virtual — which destructors would still run?

	(3)
	IOperatingSystem* can see only printInfo() and version()
	iOS::printInfo is inherited by Apple and down to iPhone16/17 — they print "iOS"
	android::printInfo is inherited by Samsung and down to GalaxyS24/25 — they print "android"
	version() resolves to the leaf override in each case
	test yourself: what would happen if printInfo were not virtual and called on IOperatingSystem*?

	(4)
	multiple inheritance means one object satisfies multiple interface types simultaneously
	the two pointers point at different subobject offsets inside the same object
	each pointer can only see the methods declared in its own interface
	the commented lines are compile errors — not runtime errors
	test yourself: uncomment one and confirm the exact compiler message

	(5)
	delete through APhone* fires the full destructor chain: ~iPhone16 → ~Apple → ~APhone / ~iOS → ~IOperatingSystem
	without virtual destructors only ~APhone would run — the derived parts would never be cleaned up
	every base class with virtual functions must have a virtual destructor
	test yourself: count how many destructor lines print and match them to the hierarchy

	(6)
	dynamic_cast checks the real type at runtime using the vtable
	it returns a valid pointer on success and nullptr on failure — safe to check
	it only works when the hierarchy has virtual functions (vtable must be present)
	test yourself: dynamic_cast<Samsung*>(p1) — what does it return and why?

	(7)
	APhone* and IOperatingSystem* are unrelated in C++'s type system — no implicit cast exists
	dynamic_cast can bridge them because the real object inherits from both
	the cast succeeds because iPhone16 satisfies both APhone and IOperatingSystem
	test yourself: try the same cross-cast starting from a GalaxyS24* pointer
*/
