#include <iostream>
#include <sstream>
#include <string>
#include <limits>

// ─── stringstream basics ──────────────────────────────────────────────────────
// std::stringstream	– read and write to an in-memory string buffer
// std::ostringstream	– write-only string stream (build output)
//
// ss.str()				– get the underlying string
// ss.str("text")		– replace the underlying string
// ss.clear()			– clear error flags (does NOT clear the buffer)
// ss >> var			– extract / parse next token into var
// ss << var			– insert var into the buffer

// ─── Converting values between types ────────────────────────────────────────
// The most common use: parse a string into a numeric type, or build a string
// from numbers without printf/to_string juggling.

void convert_string_to_int()
{
	// --- convert string to int ---
	std::string s = "42";
	int n;

	std::stringstream ss(s);
	ss >> n;

	std::cout << n + 1 << "\n";	// 43
}

void convert_int_to_string()
{
	// --- convert int to string ---
	int n = 42;
	std::ostringstream ss;
	ss << n;

	std::string s = ss.str();
	std::cout << s << "\n";	// "42"
}

void convert_multiple_tokens()
{
	// --- convert multiple tokens ---
	std::string line = "Alice 30 1.75";
	std::stringstream ss(line);

	std::string name;
	int age;
	double height;

	ss >> name >> age >> height;

	std::cout << name << " is " << age << " years old, " << height << "m tall\n";
}

// ─── Exceeding type limits sets failbit ──────────────────────────────────────
// If the parsed value overflows the target type, failbit is set and the
// variable is left unchanged (or set to the type's max, implementation-defined).

void overflow_sets_failbit()
{
	// --- overflow sets failbit ---
	// INT_MAX is 2147483647 — this value is one more
	std::string s = "2147483648";
	std::stringstream ss(s);
	int n = 0;

	ss >> n;

	if (ss.fail())
		std::cout << "overflow: failbit set, n = " << n << "\n";
	else
		std::cout << "parsed: " << n << "\n";
}

void underflow_sets_failbit()
{
	// --- underflow sets failbit ---
	// INT_MIN is -2147483648 — this is one less
	std::string s = "-2147483649";
	std::stringstream ss(s);
	int n = 0;

	ss >> n;

	if (ss.fail())
		std::cout << "underflow: failbit set, n = " << n << "\n";
	else
		std::cout << "parsed: " << n << "\n";
}

// ─── Partial reads — read pointer stops at first unparseable char ─────────────
// "1234a" parsed into int: reads 1234, stops at 'a'
// 'a' remains in the buffer and will be read by the next extraction

void partial_read()
{
	// --- partial read ---
	std::string s = "1234a";
	std::stringstream ss(s);
	int n;
	char c;

	ss >> n;	// reads 1234, stops at 'a'
	ss >> c;	// reads 'a'

	std::cout << "int: " << n << "\n";	// 1234
	std::cout << "char: " << c << "\n";	// a
}

void partial_read_mixed_line()
{
	// --- partial read mixed line ---
	std::string s = "100px 200px";
	std::stringstream ss(s);
	int a, b;
	std::string unit_a, unit_b;

	ss >> a >> unit_a >> b >> unit_b;

	std::cout << a << " " << unit_a << "\n";	// 100 px
	std::cout << b << " " << unit_b << "\n";	// 200 px
}

// ─── Scientific notation is accepted into float / double ─────────────────────
// >> automatically handles: 1.5e3  1.5E3  1.5e+3  1.5e-3  -2.4E10

void scientific_notation()
{
	// --- scientific notation ---
	std::string s = "1.5e3 2.4E-2 -3.0e+10";
	std::stringstream ss(s);
	double a, b;
	float c;

	ss >> a >> b >> c;

	std::cout << a << "\n";	// 1500
	std::cout << b << "\n";	// 0.024
	std::cout << c << "\n";	// -3e+10
}

void scientific_overflow_float()
{
	// --- scientific overflow float ---
	// float max is ~3.4e38 — this exceeds it
	std::string s = "1.0e99";
	std::stringstream ss(s);
	float f = 0.0f;

	ss >> f;

	if (ss.fail())
		std::cout << "float overflow: failbit set\n";
	else
		std::cout << "parsed: " << f << "\n";	// inf on many platforms
}

int main()
{
	convert_string_to_int();
	convert_int_to_string();
	convert_multiple_tokens();
	overflow_sets_failbit();
	underflow_sets_failbit();
	partial_read();
	partial_read_mixed_line();
	scientific_notation();
	scientific_overflow_float();

	return 0;
}
