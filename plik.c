#include <stdio.h>

int main() {
	int i = 5;
	int a = 0;
	for( i; i < 10; i++ ) {
		printf("test\n");
		a++;
	}
	printf("a = %d\n", a);
	return 0;
}
