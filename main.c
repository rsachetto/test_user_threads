#include <stdio.h>
#include <stdlib.h>

#include "../user_threads/library.h"

void print_t(void *t) {
	int a = 10;
	printf("TID: %d %d\n",  ut_getid(),a);

	for(int i = 0; i < 100000000; i++) a++;
	printf("TID: %d %d\n",  ut_getid(),a);
}

int main() {

	ut_init();

	for(int i = 0; i < 30; i++) {
		ut_create(print_t, NULL);
	}


	int st;
	for(int i = 1; i < 31; i++) {
		ut_join(i, &st);
		printf("ST: %d\n", st);
	}
}
