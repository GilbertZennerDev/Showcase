#include <stdio.h>

static inline int max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int main() {
	int a, b, c;

	printf("Enter three integers: ");
	scanf("%d %d %d", &a, &b, &c);

	int maximum = max(max(a, b), c);


	printf("maximum of %d, %d and %d = %d\n", a, b, c, maximum);
	return 0;
}
