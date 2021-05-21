#include <iostream>

extern "C" const char test[];
extern "C" const size_t test_len;


int main() {
	std::cout << "Hello World\n";
	std::cout << test << "\n";
}
