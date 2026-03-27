#include <iostream>
#include <string>
#include <limits>

// ─── Reading from Input ───────────────────────────────────────────────────────
// cin >> var				– reads one whitespace-delimited token, skips leading whitespace
// getline(cin, str)		– reads the entire line including spaces, stops at '\n'
// cin.get(ch)				– reads exactly one character, including whitespace
// cin.peek()				– peeks at next char without consuming it
// cin.ignore(n, delim)		– discards n chars or until delim (default delim is EOF)

// ─── Stream State Bits ────────────────────────────────────────────────────────
// goodbit	– no errors, stream is fully operational
// eofbit	– end of input reached (e.g. Ctrl+D on terminal, or end of piped input)
// failbit	– logical error: operation failed but stream not corrupted
//			  e.g. tried to read an int but got letters
// badbit	– fatal I/O error: stream is corrupted / unrecoverable
//			  e.g. hardware fault, buffer corruption

// Checking state:
// cin.good()	– true if goodbit is set (no errors at all)
// cin.eof()	– true if eofbit is set
// cin.fail()	– true if failbit OR badbit is set
// cin.bad()	– true if badbit is set
// !cin			– same as cin.fail()

// Recovering from a failed state:
// cin.clear()				– clears all error flags (resets to goodbit)
// cin.ignore(n, delim)		– flush leftover garbage from the buffer after clear()

// ─── Important Gotcha: mixing >> and getline ──────────────────────────────────
// >> leaves the '\n' in the buffer, so the next getline() immediately reads
// an empty string. Fix: call cin.ignore() between them.

// ─── Output ───────────────────────────────────────────────────────────────────
// cout << var		– write to stdout
// cerr << var		– write to stderr (unbuffered, always flushes immediately)
// clog << var		– write to stderr (buffered)
// cout.flush()		– manually flush stdout buffer
// cout << std::endl	– writes '\n' AND flushes (prefer '\n' alone for performance)

// ─── Examples ─────────────────────────────────────────────────────────────────

// basic >> read
void read_token()
{
	int n;
	std::cout << "Enter a number: ";
	std::cin >> n;
	std::cout << "Got: " << n << "\n";
}

// getline — reads full line including spaces
void read_line()
{
	std::string name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	std::cout << "Hello, " << name << "\n";
}

// mixing >> and getline — must flush the leftover '\n'
void read_mixed()
{
	int age;
	std::string name;

	std::cout << "Enter age: ";
	std::cin >> age;

	// without this ignore(), getline reads the leftover '\n' and gets empty string
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter name: ";
	std::getline(std::cin, name);

	std::cout << age << " " << name << "\n";
}

// handling failbit — bad input type
void handle_fail()
{
	int n;
	std::cout << "Enter a number: ";
	std::cin >> n;

	if (std::cin.fail())
	{
		std::cout << "bad input — not a number\n";
		std::cin.clear();	// clear failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// flush garbage
	}
	else
	{
		std::cout << "Got: " << n << "\n";
	}
}

// reading until eof (e.g. piped input or redirected file)
void read_until_eof()
{
	std::string line;
	while (std::getline(std::cin, line))
	{
		std::cout << "> " << line << "\n";
	}

	if (std::cin.eof())
		std::cout << "end of input\n";

	if (std::cin.bad())
		std::cerr << "fatal stream error\n";
}

int main()
{
	read_token();
	return 0;
}
