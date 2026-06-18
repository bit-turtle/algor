// Main Test File

#include <stdlib.h>
#include <stdio.h>
#include "test.h"

unsigned total = 0;
unsigned successes = 0;

void* newint(int num) {
	int* n = malloc(sizeof(int));
	*n = num;
	return (void*)n;
}

bool compareint(void* a, void* b) {
	return *(int*)a > *(int*)b;
}

char* stringint(void* z) {
	char* number = (char*)malloc(20);
	snprintf(number, 20, "%d", *(int*)z);
	return number;
}

void test(const char* name, bool passed) {
	printf("%s test %s\n", name, passed ? "PASSED" : "FAILED");
	total++;
	if (passed)
		successes++;
}

int main() {
	binary();
	search();
	heap();
	printf("%u of %u tests passed\n", successes, total);
	return total - successes;
}
