#include "04-overloading.hpp"
#include <cstring>
#include <cctype>
#include <iostream>

/* constructors */
FTString::FTString()
	:	str(new char[1]()), len(0)
{}

FTString::FTString(const char* s) {
	len = std::strlen(s);
	str = new char[len + 1];
	std::memcpy(str, s, len + 1);
}

FTString::FTString(const FTString& other)
	:	len(other.len)
{
	str = new char[len + 1];
	std::memcpy(str, other.str, len + 1);
}

FTString& FTString::operator=(const FTString& other) {
	if (this != &other)
		replace_str(other.str, other.len);
	return *this;
}

FTString::~FTString() {
	delete[] str;
}

/* operator overload */
FTString FTString::operator+(const FTString& other) const {
	size_t		new_len = len + other.len;
	char*		buf = new char[new_len + 1];

	std::memcpy(buf, str, len);
	std::memcpy(buf + len, other.str, other.len + 1);
	FTString	result(buf);
	delete[] buf;
	return result;
}

FTString FTString::operator+(const char* s) const {
	return *this + FTString(s);
}

FTString& FTString::operator++() {
	for (size_t i = 0; i < len; i++)
		str[i] = (char)std::toupper((unsigned char)str[i]);
	return *this;
}

FTString FTString::operator++(int) {
	FTString	original(*this);
	for (size_t i = 0; i < len; i++)
		str[i] = (char)std::toupper((unsigned char)str[i]);
	return original;
}

FTString FTString::operator*(int times) const {
	if (times <= 0)
		return FTString();
	
	size_t	new_len = len * (size_t)times;
	char*	buf = new char[new_len + 1];
	
	for (int i = 0; i < times; i++)
		std::memcpy(buf + len * i, str, len);
	buf[new_len] = '\0';
	
	FTString	result(buf);
	delete[] buf;
	return result;
}

FTString FTString::operator-() const {
	FTString result(*this);
	for (size_t i = 0; i < len / 2; i++) {
		char tmp = result.str[i];
		result.str[i] = result.str[len - 1 - i];
		result.str[len - 1 - i] = tmp;
	}
	return result;
}

void FTString::operator>>(int& i) const {
	i = std::atoi(str);
}

void FTString::operator>>(unsigned int& u) const {
	u = (unsigned int)std::strtoul(str, NULL, 10);
}

/* access overload */
char FTString::operator[](size_t index) const {
	return str[index];
}

size_t	FTString::operator[](char c) const {
	size_t count = 0;
	for (size_t i = 0; i < len; i++) {
		if (str[i] == c)
			count++;
	}
	return count;
}

char* FTString::operator[](const char *str) const {
	return std::strstr(this->str, str);
}


/* boolean overload */
bool FTString::operator==(const FTString& other) const {
	return std::strcmp(str, other.str) == 0;
}

bool FTString::operator!=(const FTString& other) const {
	return !(*this == other);
}

bool FTString::operator>(const FTString& other) const {
	return std::strcmp(str, other.str) > 0;
}

bool FTString::operator<(const FTString& other) const {
	return std::strcmp(str, other.str) < 0;
}

bool FTString::operator>=(const FTString& other) const {
	return !(*this < other);
}

bool FTString::operator<=(const FTString& other) const {
	return !(*this > other);
}

/* functions overload */
void FTString::ft_print() const {
	std::cout << str << '\n';
}

void FTString::ft_print(int times) const {
	for (int i = 0; i < times; i++)
		std::cout << str << '\n';
}

/* methods */
char* FTString::c_str() const {
	return str;
}

size_t FTString::length() const {
	return len;
}

/* utils */
void FTString::replace_str(const char* s, size_t new_len) {
	delete[] str;
	len = new_len;
	str = new char[len + 1];
	std::memcpy(str, s, len + 1);
}

std::ostream& operator<<(std::ostream& os, const FTString& obj)
{
	os	<< "string: " << obj.c_str() << "\n"
		<< "length: " << obj.length();
	return os;
}
