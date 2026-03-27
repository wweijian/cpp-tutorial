#include <iostream>

void increment(int& n) { n++; }
void decrement(int* n) { (*n)--; }
void square (int n) { n *= n; }

int main() {

	int *ptr = new int(5); // (0)
	const int *ptr2 = new const int (10); // (1)

	std::cout << "Initial value: " << *ptr << std::endl; 
	increment(*ptr); // (2)
	std::cout << "After increment: " << *ptr << std::endl;
	decrement(ptr); // (3)
	std::cout << "After decrement: " << *ptr << std::endl;
	square(*ptr); // (4)
	std::cout << "After square: " << *ptr << std::endl;

	delete ptr; // (5)
	delete ptr2;
}

/* 
	notes:

	(0)
	new is the key word used to dynamically allocate memory on the heap
	it returns a pointer to the allocated memory
	which can be used to access and manipulate the value stored at that location.

	(1)
	you can also use new to allocate memory for a const int,
	which means the value stored at that location cannot be modified through that pointer.

	(2)
	passing by reference allows us to modify the the original variable by 
	using the data type directly,
	(note: unlike C where you have to derefererence the pointer, you can access it directly)

	(3)
	passing the pointer is the same as C
	you are still passing the address of the variable 
	and you have to dereference it to access the value

	(4)
	passing by value creates a copy of the variable and does not affect the original. 
	
	In this example, increment modifies the original variable through reference, 
	while square does not modify the original variable since it is passed by value. 
	The decrement function modifies the original variable through a pointer.

	(5)
	to delete the memory that you have allocated on the heap
	use the delete operator
	for 42, you won't be able to use malloc and free, so this it the only way if you need to malloc

	one reason that having to malloc is good is that
	when you're writing your class, and you don't want to initialize a value right away
	because when unsepcified the default constructor will be called on the variable
	but then you want to const it or you just don't want to reassign it

*/
