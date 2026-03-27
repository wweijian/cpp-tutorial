#include <string>
#include <iostream>

int main (int ac , char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " <string>" << std::endl;
		return 1;
	}

	// copy constructor
	std::string str(av[1]);

	// assignment operator
	std::string str2;
	str2 = av[1];

	// --- size / empty ---
	std::cout << "str: " << str << std::endl;
	std::cout << "size: " << str.size() << std::endl;
	std::cout << "empty: " << (str.empty() ? "true" : "false") << std::endl;

	// --- at / [] ---
	// [] does no bounds checking; at() throws std::out_of_range
	std::cout << "str[0]: " << str[0] << std::endl;
	std::cout << "str.at(0): " << str.at(0) << std::endl;

	// --- c_str ---
	// returns a null-terminated const char* (needed for C APIs)
	const char *cstr = str.c_str();
	std::cout << "c_str: " << cstr << std::endl;

	// --- append / += ---
	std::string appended = str;
	appended.append(" world");
	appended += "!";
	std::cout << "appended: " << appended << std::endl;

	// --- find / rfind ---
	// find returns the index of the first match, or std::string::npos if not found
	std::string sentence = "the cat sat on the mat";
	size_t first = sentence.find("at");
	size_t last  = sentence.rfind("at");
	std::cout << "find(\"at\"): " << first << std::endl;
	std::cout << "rfind(\"at\"): " << last << std::endl;
	if (sentence.find("dog") == std::string::npos)
		std::cout << "\"dog\" not found" << std::endl;

	// --- substr ---
	// substr(pos, len) — len is optional (defaults to end of string)
	std::string sub = sentence.substr(4, 3);   // "cat"
	std::cout << "substr(4, 3): " << sub << std::endl;

	// --- compare ---
	// returns 0 if equal, <0 if less, >0 if greater
	std::string a = "apple";
	std::string b = "banana";
	int cmp = a.compare(b);
	if (cmp == 0)
		std::cout << "equal" << std::endl;
	else if (cmp < 0)
		std::cout << a << " comes before " << b << std::endl;
	else
		std::cout << a << " comes after " << b << std::endl;

	return 0;
}
