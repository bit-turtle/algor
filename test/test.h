// Test Header
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void* newint(int z);
bool compareint(void* a, void* b);
void test(const char* name, bool passed);

// Tests
void binary();
void search();
void heap();
