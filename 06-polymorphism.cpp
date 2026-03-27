#include <iostream>
#include "06-polymorphism.hpp"

// APhone
APhone::APhone(const std::string &colour, size_t storage, size_t ram)
	: colour(colour), storage(storage), ram(ram)
{
	std::cout << "APhone::APhone(" << colour << ", " << storage << "GB, " << ram << "GB)" << std::endl;
}

APhone::~APhone() {}

// IOperatingSystem
IOperatingSystem::~IOperatingSystem() {}

// iOS
iOS::iOS() {}

iOS::~iOS() {}

void	iOS::printInfo() const
{
	std::cout << "iOS" << std::endl;
}

// android
android::android() {}

android::~android() {}

void	android::printInfo() const
{
	std::cout << "android" << std::endl;
}

// Apple
Apple::Apple(const std::string &colour, size_t storage, size_t ram)
	: APhone(colour, storage, ram), iOS()
{
	std::cout << "Apple::Apple" << std::endl;
}

Apple::~Apple() {}

// Samsung
Samsung::Samsung(const std::string &colour, size_t storage, size_t ram)
	: APhone(colour, storage, ram), android()
{
	std::cout << "Samsung::Samsung" << std::endl;
}

Samsung::~Samsung() {}

// iPhone16
iPhone16::iPhone16(const std::string &colour, size_t storage, size_t ram)
	: Apple(colour, storage, ram)
{
	std::cout << "iPhone16::iPhone16" << std::endl;
}

iPhone16::~iPhone16()
{
	std::cout << "iPhone16::~iPhone16" << std::endl;
}

void	iPhone16::call(const std::string &number) const
{
	std::cout << "iPhone 16 (" << colour << ") calling " << number << std::endl;
}

void	iPhone16::version() const
{
	std::cout << "iOS 16" << std::endl;
}

// iPhone17
iPhone17::iPhone17(const std::string &colour, size_t storage, size_t ram)
	: Apple(colour, storage, ram)
{
	std::cout << "iPhone17::iPhone17" << std::endl;
}

iPhone17::~iPhone17()
{
	std::cout << "iPhone17::~iPhone17" << std::endl;
}

void	iPhone17::call(const std::string &number) const
{
	std::cout << "iPhone 17 (" << colour << ") calling " << number << std::endl;
}

void	iPhone17::version() const
{
	std::cout << "iOS 17" << std::endl;
}

// GalaxyS24
GalaxyS24::GalaxyS24(const std::string &colour, size_t storage, size_t ram)
	: Samsung(colour, storage, ram)
{
	std::cout << "GalaxyS24::GalaxyS24" << std::endl;
}

GalaxyS24::~GalaxyS24()
{
	std::cout << "GalaxyS24::~GalaxyS24" << std::endl;
}

void	GalaxyS24::call(const std::string &number) const
{
	std::cout << "Galaxy S24 (" << colour << ") calling " << number << std::endl;
}

void	GalaxyS24::version() const
{
	std::cout << "android 14" << std::endl;
}

// GalaxyS25
GalaxyS25::GalaxyS25(const std::string &colour, size_t storage, size_t ram)
	: Samsung(colour, storage, ram)
{
	std::cout << "GalaxyS25::GalaxyS25" << std::endl;
}

GalaxyS25::~GalaxyS25()
{
	std::cout << "GalaxyS25::~GalaxyS25" << std::endl;
}

void	GalaxyS25::call(const std::string &number) const
{
	std::cout << "Galaxy S25 (" << colour << ") calling " << number << std::endl;
}

void	GalaxyS25::version() const
{
	std::cout << "android 15" << std::endl;
}
