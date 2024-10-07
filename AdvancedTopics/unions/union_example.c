#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

union Data2 {
	int i;
	float f;
	char str[20];
};

int main() {
    union Data data;
    union Data2 data2;

    data.i = 10;
    data2.i = 20;
    printf("data.i: %d\n", data.i);
    printf("data2.i: %d\n", data2.i);

    data.f = 220.5;
    printf("data.f: %.2f\n", data.f);
 
    data2.f = 450.5;
    printf("data2.f: %.2f\n", data2.f);


    strcpy(data.str, "C Programming");
    printf("data.str: %s\n", data.str);
 
    strcpy(data2.str, "C Programming");
    printf("data2.str: %s\n", data2.str);


    return 0;
}
