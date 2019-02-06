#include<stdio.h>
extern char p[];
extern void f();

int main() {
	f();
	printf("a.c: %s\n", p);
	return 0;
}
