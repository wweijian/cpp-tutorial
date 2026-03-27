#include <fstream>
#include <iostream>
#include <string>

// ─── Modes ────────────────────────────────────────────────────────────────────
// ios::in		– read
// ios::out		– write (truncates)
// ios::app		– append
// ios::trunc	– truncate on open
// Combine with |:	ios::in | ios::out

// ─── Open / Close ─────────────────────────────────────────────────────────────
// stream.open(filename, mode)	 – open a file
// stream.close()				 – close the file
// stream.is_open()				 – true if file is open

// ─── Input (ifstream / fstream) ───────────────────────────────────────────────
// stream >> var				 – read formatted token
// getline(stream, str)			 – read entire line into string
// stream.get(ch)				 – read single character
// stream.read(buf, n)			 – read n bytes into buffer (binary)
// stream.peek()				 – peek at next char without consuming
// stream.ignore(n, delim)		 – skip n chars or until delim
// stream.eof()					 – true at end of file

// ─── Output (ofstream / fstream) ──────────────────────────────────────────────
// stream << var				 – write formatted output
// stream.put(ch)				 – write single character
// stream.write(buf, n)			 – write n bytes from buffer (binary)
// stream.flush()				 – flush buffer to file

// ─── State Checks ─────────────────────────────────────────────────────────────
// stream.good()   – no errors
// stream.fail()   – logical error (bad format, etc.)
// stream.bad()	   – fatal I/O error
// stream.eof()	   – end of file reached
// stream.clear()  – clear error flags

// ─── Examples ─────────────────────────────────────────────────────────────────

void write_example()
{
	std::ofstream out("file.txt");
	out << "Hello\n";
	out.close();
}

void read_example()
{
	std::ifstream in("Makefile.txt");
	std::string line;
	while (std::getline(in, line))
	{
		std::cout << line << std::endl;
	}
	in.close();
}

void readwrite_example()
{
	std::fstream rw("file.txt", std::ios::in | std::ios::out);
	rw.seekg(0, std::ios::beg);	 // reset pointer for reading
	rw.seekp(0, std::ios::end);	 // move pointer to end for writing
	rw.close();
}

// getline with a custom delimiter
// by default getline reads until '\n', but you can pass a third argument
void getline_example()
{
	std::ofstream out("data.txt");
	out << "alice,bob,charlie\n";
	out << "line two\n";
	out.close();

	std::ifstream in("data.txt");
	std::string token;

	// read comma-separated tokens on the first line
	while (std::getline(in, token, ','))
	{
		std::cout << token << "\n";	 // prints: alice  bob	charlie
	}

	// after the comma loop, the stream is still open — read remaining lines
	std::string line;
	while (std::getline(in, line))
	{
		std::cout << line << "\n";
	}

	in.close();
}

// checking eof — the right way
// eof() only becomes true AFTER a failed read, not before
// so always loop on the read operation itself, not on eof()
void eof_example()
{
	std::ofstream out("nums.txt");
	out << "1\n2\n3\n";
	out.close();

	std::ifstream in("nums.txt");
	int n;

	// good: the >> returns false when read fails (including at eof)
	while (in >> n)
	{
		std::cout << n << "\n";
	}

	// after the loop, check why it stopped
	if (in.eof())
		std::cout << "reached end of file\n";

	in.close();
}

// checking fail / bad bits
// fail: logical error — e.g. tried to read an int but got a letter
// bad:	 hardware / OS level I/O error — buffer corruption, etc.
void error_bit_example()
{
	std::ofstream out("mixed.txt");
	out << "42 hello\n";
	out.close();

	std::ifstream in("mixed.txt");
	int a, b;

	in >> a;  // succeeds: a == 42
	in >> b;  // fails: "hello" cannot be read into int

	if (in.fail() && !in.bad())
		std::cout << "logical read error (failbit set)\n";

	if (in.bad())
		std::cout << "fatal I/O error (badbit set)\n";

	// clear the error flags so the stream is usable again
	in.clear();

	std::string leftover;
	in >> leftover;	 // now reads "hello"
	std::cout << "leftover: " << leftover << "\n";

	in.close();
}

int main()
{
	write_example();
	read_example();
	readwrite_example();
	getline_example();
	eof_example();
	error_bit_example();
	return 0;
}
