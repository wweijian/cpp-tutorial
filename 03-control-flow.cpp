#include <iostream>
#include <string>

int main ()
{
	
	for (int i = 0; i < 5; i++) { // (0)
		switch (i) { // (1)
			case 0:
				std::cout << "i is zero" << std::endl;
				// break; (2)
			case 1:
				std::cout << "i is one" << std::endl;
				break;
			case 2:
				std::cout << "i is two" << std::endl;
				break;
			default:
				std::cout << "i is greater than two" << std::endl;
		}
		std::cout << "i: " << i << std::endl;
	}
	// std::cout << "i after loop: " << i << std::endl; // (3)

	int i = 1; // (4)
	int k = 0;
	for (int i = 0, j = 0; i < 5 && j < 10; i++, j+=2) { // (5)
		std::cout << "i: " << i << ", j: " << j << ", k: " << k << std::endl;
		k++;
	}
	std::cout << "i after loop: " << i << std::endl; // (6)

	int x = i == 1 ? 100 : 200; // (7)
	(void)x;
}

/* 
	notes:

	(0)
	previously norminette didn't allow us to use for loops and swtich statements
	so this is just to show that we can use them now
	the structure is: 
	for (initialization; condition; increment) {
		// code to be executed
	}

	(1)
	this is a switch statement
	which basically means match the value of i with the cases
	for C/C++, it only works with characters and integers
	if you have worked on languages like python, switch statements can be used
	with strings and other data types as well

	(2)
	the break statement is used to exit the switch statement
	if you don't use break, it will continue to execute the next cases until it hits a break
	or a return
	notice this break doesn't break the outer for loop

	(3)
	scope
	the variable i is only accessible within the for loop

	(4)
	you can also declare a variable outside the for loop and use it inside the for loop
	for conflicting names, the variable declared inside the for loop will take precedence

	(5)
	you can use commas to separate multiple statements in the initialization and increment sections of the for loop

	(6)
	the variable i declared outside the for loop is not affected by the for loop
	as it was shadowed by the i declared inside the for loop

	(7)
	the ternary operator is a shorthand for an if-else statement
*/
