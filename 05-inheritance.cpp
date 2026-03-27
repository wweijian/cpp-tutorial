#include <iostream>
#include "05-inheritance.hpp"

// Base
Base::Base()
	: public_variable1("Base::public_variable1"),
	  public_variable2("Base::public_variable2"),
	  protected_variable1("Base::protected_variable1"),
	  protected_variable2("Base::protected_variable2"),
	  private_variable1("Base::private_variable1"),
	  private_variable2("Base::private_variable2")
{
	std::cout << "Base::Base" << std::endl;
}

Base::Base(const std::string& str)
	: public_variable1(str + " ::public_variable1"),
	  public_variable2(str + " ::public_variable2"),
	  protected_variable1(str + " ::protected_variable1"),
	  protected_variable2(str + " ::protected_variable2"),
	  private_variable1(str + " ::private_variable1"),
	  private_variable2(str + " ::private_variable2")
{
	std::cout << "Base::Base" << std::endl;
}

Base::Base(const Base& other)
	: public_variable1(other.public_variable1),
	  public_variable2(other.public_variable2),
	  protected_variable1(other.protected_variable1),
	  protected_variable2(other.protected_variable2),
	  private_variable1(other.private_variable1),
	  private_variable2(other.private_variable2)
{
	std::cout << "Base::Base(copy)" << std::endl;
}

Base& Base::operator=(const Base& other)
{
	std::cout << "Base::operator=" << std::endl;
	if (this == &other) return *this;
	public_variable1 = other.public_variable1;
	public_variable2 = other.public_variable2;
	protected_variable1 = other.protected_variable1;
	protected_variable2 = other.protected_variable2;
	private_variable1 = other.private_variable1;
	private_variable2 = other.private_variable2;
	return *this;
}

Base::~Base()
{
	std::cout << "Base::~Base" << std::endl;
}

void Base::public_function1()
{
	std::cout << "Base::public_function1" << std::endl;
}

void Base::public_function2()
{
	std::cout << "Base::public_function2" << std::endl;
}

void Base::non_virtual_function()
{
	std::cout << "Base::non_virtual_function" << std::endl;
}

void Base::protected_function1()
{
	std::cout << "Base::protected_function1" << std::endl;
}

void Base::protected_function2()
{
	std::cout << "Base::protected_function2" << std::endl;
}

void Base::private_function1()
{
	std::cout << "Base::private_function1" << std::endl;
}

void Base::private_function2()
{
	std::cout << "Base::private_function2" << std::endl;
}

// PublicDerived
PublicDerived::PublicDerived()
	: Base("PublicDerived"),
	  public_variable2("PublicDerived::public_variable2"),
	  protected_variable2("PublicDerived::protected_variable2"),
	  private_variable2("PublicDerived::private_variable2")
{
	std::cout << "PublicDerived::PublicDerived" << std::endl;
}

PublicDerived::PublicDerived(const PublicDerived& other)
	: Base(other), // (0)
	  public_variable2(other.public_variable2),
	  protected_variable2(other.protected_variable2),
	  private_variable2(other.private_variable2)
{
	std::cout << "PublicDerived::PublicDerived(copy)" << std::endl;
}

PublicDerived& PublicDerived::operator=(const PublicDerived& other)
{
	std::cout << "PublicDerived::operator=" << std::endl;
	if (this == &other) return *this;
	Base::operator=(other); // (1)
	public_variable2 = other.public_variable2;
	protected_variable2 = other.protected_variable2;
	private_variable2 = other.private_variable2;
	return *this;
}

PublicDerived::~PublicDerived()
{
	std::cout << "PublicDerived::~PublicDerived" << std::endl;
}

void PublicDerived::public_function2()
{
	std::cout << "PublicDerived::public_function2" << std::endl;
}

void PublicDerived::protected_function2()
{
	std::cout << "PublicDerived::protected_function2" << std::endl;
}

void PublicDerived::private_function2()
{
	std::cout << "PublicDerived::private_function2" << std::endl;
}

// ProtectedDerived
ProtectedDerived::ProtectedDerived()
	: Base("ProtectedDerived"),
	  public_variable2("ProtectedDerived::public_variable2"),
	  protected_variable2("ProtectedDerived::protected_variable2"),
	  private_variable2("ProtectedDerived::private_variable2")
{
	std::cout << "ProtectedDerived::ProtectedDerived" << std::endl;
}

ProtectedDerived::~ProtectedDerived()
{
	std::cout << "ProtectedDerived::~ProtectedDerived" << std::endl;
}

void ProtectedDerived::public_function2()
{
	std::cout << "ProtectedDerived::public_function2" << std::endl;
}

void ProtectedDerived::protected_function2()
{
	std::cout << "ProtectedDerived::protected_function2" << std::endl;
}

void ProtectedDerived::private_function2()
{
	std::cout << "ProtectedDerived::private_function2" << std::endl;
}

// PrivateDerived
PrivateDerived::PrivateDerived()
	: Base("PrivateDerived"), // (0)
	  public_variable2("PrivateDerived::public_variable2"),
	  protected_variable2("PrivateDerived::protected_variable2"),
	  private_variable2("PrivateDerived::private_variable2")
{
	std::cout << "PrivateDerived::PrivateDerived" << std::endl;
}

PrivateDerived::~PrivateDerived()
{
	std::cout << "PrivateDerived::~PrivateDerived" << std::endl;
}

void PrivateDerived::public_function2()
{
	std::cout << "PrivateDerived::public_function2" << std::endl;
}

void PrivateDerived::protected_function2()
{
	std::cout << "PrivateDerived::protected_function2" << std::endl;
}

void PrivateDerived::private_function2()
{
	std::cout << "PrivateDerived::private_function2" << std::endl;
}

// OtherDerived1
OtherDerived1::OtherDerived1()
	: Base("OtherDerived1"),
	  public_variable2("OtherDerived1::public_variable2")
{
	std::cout << "OtherDerived1::OtherDerived1" << std::endl;
}

OtherDerived1::~OtherDerived1()
{
	std::cout << "OtherDerived1::~OtherDerived1" << std::endl;
}

void OtherDerived1::public_function2()
{
	std::cout << "OtherDerived1::public_function2" << std::endl;
}

// OtherDerived2
OtherDerived2::OtherDerived2()
	: Base("OtherDerived2"),
	  public_variable2("OtherDerived2::public_variable2")
{
	std::cout << "OtherDerived2::OtherDerived2" << std::endl;
}

OtherDerived2::~OtherDerived2()
{
	std::cout << "OtherDerived2::~OtherDerived2" << std::endl;
}

void OtherDerived2::public_function2()
{
	std::cout << "OtherDerived2::public_function2" << std::endl;
}

// HidingDerived
HidingDerived::HidingDerived()
	: Base("HidingDerived")
{
	std::cout << "HidingDerived::HidingDerived" << std::endl;
}

HidingDerived::~HidingDerived()
{
	std::cout << "HidingDerived::~HidingDerived" << std::endl;
}

void HidingDerived::non_virtual_function(int x)
{
	std::cout << "HidingDerived::non_virtual_function(" << x << ")" << std::endl;
}

// DiamondDerived
void DiamondDerived::public_function2()
{
	std::cout << "DiamondDerived::public_function2" << std::endl;
}

DiamondDerived::DiamondDerived()
	: Base("DiamondDerived"),
	  public_variable2("DiamondDerived::public_variable2"),
	  protected_variable2("DiamondDerived::protected_variable2"),
	  private_variable2("DiamondDerived::private_variable2")
{
	std::cout << "DiamondDerived::DiamondDerived" << std::endl;
}

DiamondDerived::~DiamondDerived()
{
	std::cout << "DiamondDerived::~DiamondDerived" << std::endl;
}

/*
	notes:

	(0)
	when you are inherting, you can explicitly call the base class constructor
	otherwise, it'll call your default constructor

	(0) in PublicDerived copy constructor
	Base(other) forwards the derived object as a Base reference to Base's copy constructor
	if you omit this, Base() runs instead — the derived copy constructor would not copy Base's members

	(1)
	Base::operator=(other) explicitly calls the base assignment operator
	without it, Base's members are not reassigned — only the derived part updates

*/
