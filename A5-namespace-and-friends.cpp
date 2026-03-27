#include <string>
#include <iostream>

class Loner;
class MrFriendly;	// forward declare so OtherLoner::greet can reference it later

class OtherLoner {
	public:
		OtherLoner() {}
		~OtherLoner() {}

		void greet();	// defined after MrFriendly is complete
};

class MrFriendly {
	public:
		MrFriendly() : name("MrFriendly") {}
		~MrFriendly() {}

	private:
		std::string name;

	friend class Loner;
	friend void OtherLoner::greet();	// OtherLoner is now complete, so this is valid
};

class Loner {
	public:
		Loner() {}
		~Loner() {}

		void greet() {
			MrFriendly mf;
			std::cout << "Hello, " << mf.name << "!\n";	// Loner can access private member of MrFriendly
		};
};

void OtherLoner::greet() {
	MrFriendly mf;
	std::cout << "Hello, " << mf.name << "!\n";	// OtherLoner::greet is a friend of MrFriendly
}

namespace tests {
	void greetmf()
	{
		MrFriendly mf;
		Loner l;
		OtherLoner ol;
		l.greet();
		ol.greet();
	}
}

using namespace tests;

int main ()
{
	greetmf();
}
