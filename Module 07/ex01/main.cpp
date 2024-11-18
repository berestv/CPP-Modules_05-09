#include "iter.hpp"

int main() {
	std::string arr[] = { "abc", "def", "ghi", "jkl" };
	size_t len = sizeof(arr) / sizeof(arr[0]);

	iter(arr, len, print);
}
